#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(){
  char str[MAX][MAX];
  FILE *fp1,*fp2;
  if((fp1=fopen("file51.txt","r+"))==NULL){
    printf("cannot open file1!");
    exit(1);
  }
  else if((fp2=fopen("file51out.txt","r+"))==NULL){
    printf("cannot open file2!");
    exit(1);
  }
  else{
    printf("open file successfully!\n\n");
    char s[MAX]="";
    int len;
    while((fgets(s,MAX,fp1))!=NULL){
      len=strlen(s);
      fprintf(fp2,"%d %s",len,s);
      printf("%s",s);
    }
  }
  return 0;
}

