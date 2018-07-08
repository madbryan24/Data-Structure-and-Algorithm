#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {SUCCESS, FAIL};

void cat (FILE *f)
{
  int c;
  while ((c = fgetc(f)) != EOF)
    putchar(c);
}

void cat_p (FILE *f)
{
  int c;
  int line=0, cha=0;
  while ((c = fgetc(f)) != EOF)
    {
      putchar(c);
      cha++;
      if ((cha == 80) || (c == '\n'))
	{
	  line++;
	  cha = 0;
	}
      if (line == 25)
	{
	  getchar();
	  line = 0;
	}
    }
}

int main(int argc, char* argv[])
{
  if ((argc != 2 && argc != 3) || (argc == 3 && strcmp(argv[2],"-p") != 0))
    {
      printf("Wrong syntax!\n");
      printf("Should be:\n");
      printf("- cat <file> : display content to the end\n");
      printf("- cat <file> -p : view page by page\n");
    }
  else
    {
      FILE *f;
      char filename[20];
      strcpy(filename, argv[1]);
      int reval = SUCCESS;
      if ((f = fopen(filename, "r")) == NULL)
	{
	  printf("Cannot open %s\n", filename);
	  reval = FAIL;
	}
      else
	{
	  if (argc == 2) cat(f);
	  else if ((argc == 3) && (strcmp(argv[2],"-p") == 0))
	    cat_p(f);
	  fclose(f);
	}
      return reval;
    }
}
