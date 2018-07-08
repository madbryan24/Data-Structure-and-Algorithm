#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
  FILE *fp1,*fp2;
  char c;

  if((fp1=fopen("file1.txt","r"))==NULL){
    printf("Cannot open file1!");
    exit(1);
  }
  else if((fp2=fopen("file2.txt","w"))==NULL){
    printf("Cannot open file2!");
    exit(1);
  }
  else{
    printf("open file successfully\n\n");
    while((c=fgetc(fp1))!=EOF){
      if(c>='a'&&c<='z') c=toupper(c);
      else if(c>='A'&&c<='Z') c=tolower(c);

      fputc(c,fp2); // write content to file2
      putchar(c); // display file on the screen
    }
    printf("\n");
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
