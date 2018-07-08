#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define max 100


int main()
{

  int option, c, n;
  float duration;
  char str[80];
  char string[max];

  clock_t start, finish;
  FILE *fp1, *fp2;


  do {
  printf("\nCopy-Multimode\n");
  printf("1. Copy character by character\n");
  printf("2. Copy line by line\n");
  printf("3. Copy by block\n");
  printf("4. Exit\n");
  printf("Enter your option: ");
  scanf("%d", &option);

  if (option==1)
  {
    fp1=fopen("41essay.txt","r");
    fp2=fopen("41bicode.txt", "w");
    rewind(fp1);
    rewind(fp2);
    start=clock();
    while((c=fgetc(fp1))!=EOF)
    {
      fputc(c,fp2);
    }
    finish=clock();
    duration=(float)(finish-start)/CLOCKS_PER_SEC;
    printf("The duration of Copying character by character: %fs\n"
    , duration);

    fclose(fp1);
    fclose(fp2);

  }

  if (option==2)
  {
    fp1=fopen("41essay.txt","r");
    fp2=fopen("41bicode.txt", "w");
    rewind(fp1);
    rewind(fp2);
    start=clock();
    while(!feof(fp1))
    {
      fgets(str,80,fp1);
      fputs(str,fp2);
    }
    finish=clock();
    duration=(float)(finish-start)/CLOCKS_PER_SEC;
    printf("The duration of Copying line by line: %fs\n"
    , duration);

    fclose(fp1);
    fclose(fp2);
  }

  if (option==3)
  {
    fp1=fopen("41essay.txt","r");
    fp2=fopen("41bicode.txt", "w");
    printf("Enter the number of elements in a block: ");
    scanf("%d", &n);
    rewind(fp1);
    rewind(fp2);
    start=clock();
    while(!feof(fp1))
    {
      fread(string, sizeof(char), n, fp1);
      fwrite(string, sizeof(char), n, fp2);
    }
    finish=clock();
    duration=(float)(finish-start)/CLOCKS_PER_SEC;
    printf("The duration of Copying by Block of %d elements: %fs\n"
    ,n, duration);

    fclose(fp1);
    fclose(fp2);
  }

  else if (option!=1 && option !=2 && option !=3 && option !=4)
  printf("\nInvalid option, please try again!\n");

  }
  while (option!=4);


return 0;
}
