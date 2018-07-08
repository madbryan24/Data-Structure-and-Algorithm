#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

int charCounter(FILE *f)
{
  int c, count =0;
  while((c=fgetc(f))) {
  if(c == EOF) break;
  else count++;
  }
return count;
}


int main(int argc, char *argv[])
{
// variables declaring --------------------------------
  FILE *fp;
  char badWord[max][16]={"fuck","slut","bitch", "nigga"};
  char *fContent;
  char temp[16];
  int c, n;
  int i=0, j;

//-------------------------------------------------------
  if (argc != 3) {
  printf("Invalid syntax! Too few or many parameters.\n ");
  exit(0);
  }

  else
  {
  fp = fopen(argv[1],"r");
  if (fp == NULL) printf("Cannot open file %s", argv[1]);

  n=charCounter(fp);
  fContent = (char*)malloc(n*sizeof(char));

   rewind(fp);

    while((fscanf(fp, "%s", temp))!=EOF)
    {
          int check = 0;

          for (i=0; i<n; i++)
          {
            if(strcmp(temp,badWord[i])==0)
            {
              for(j=0;j<strlen(badWord[i]); j++)
                printf("%s", argv[2]);
                printf(" ");
              check = 1;
              break;
            }
          }
            if (check==0) printf("%s ", temp);
    }

    }

printf("\n" );


  fclose(fp);
return 0;
}
