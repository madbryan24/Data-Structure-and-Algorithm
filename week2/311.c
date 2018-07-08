#include <stdio.h>
int upper(FILE *fptr)
{
  char c;
  if (fptr == NULL)
    {
      printf("Unable to open file\n");
      return -1;
    }
  else
    {
      while (c != EOF)
        {
	  c = fgetc(fptr);
	  if ((c >= 'a') && (c <= 'z'))
            {
	      c = c - 32;
	      fseek(fptr,-1,SEEK_CUR);
	      fputc(c,fptr);
            }
        }
      return 0;
    }
}
int main(int argc,char *argv[])
{
  FILE *fptr;
  int a;
  if (argc == 1)
    {
      printf("No File name is provided at command line.\n");
    }
  else if (argc == 2)
    {
      fptr = fopen(argv[1],"r+");
      a = upper(fptr);
      if (a == 0)
        {
	  printf("The content of \"%s\" was transformed to uppercase.\n",argv[1]);
        }
      if (a == -1)
        {
	  printf("Failed to convert.\n");
        }
    }
  else if (argc > 2)
    {
      printf("Wrong number of argument!\n");
      return 1;
    }
}
