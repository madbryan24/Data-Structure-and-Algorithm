#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(){
  FILE *fp1,*fp2,*fp3;
  if((fp1=fopen("file62.txt","r+"))==NULL){
    printf("cannot open file1!");
    exit(1);
  }
  else if((fp2=fopen("file62.txt","r+"))==NULL){
    printf("cannot open file2!");
    exit(1);
  }
  else if((fp3=fopen("file63.txt","r+"))==NULL){
    printf("cannot open file3!");
    exit(1);
  }
  else{
    char s1[MAX]="";
    char s2[MAX]="";
    char s[MAX]="";
    
    while(fgets(s1,MAX,fp1) != NULL && fgets(s2,MAX,fp2) != NULL ){
      fputs(s1,fp3);
      fputs(s2,fp3);
    }
    if(fgets(s1,MAX,fp1) != NULL && fgets(s2,MAX,fp2) == NULL){
    while(fgets(s1,MAX,fp1) != NULL) fputs(s1,fp3);
    }
  else if(fgets(s1,MAX,fp1) != NULL && fgets(s2,MAX,fp2) == NULL){
    while(fgets(s2,MAX,fp2) != NULL) fputs(s2,fp3);
    }
    while(fgets(s,MAX,fp3)!=NULL){
      puts(s);
    }
  }
fclose(fp1);
fclose(fp2);
fclose(fp3);
  return 0;
}

