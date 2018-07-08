#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
int main(int argc,char* argv[]){
    while(argc != 3){
        printf("the number of arguments should be 3!");
        exit(1);
    }
    FILE *fp1,*fp2;
    char filename1[MAX]="";
    char filename2[MAX]="";
    strcat(filename1,argv[1]);
    strcat(filename2,argv[2]);
    if((fp1=fopen(filename1,"r"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else if((fp2=fopen(filename2,"w"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        int i=0;
        printf("open file successfully!\n");
        char s[MAX]="";
        char c;
        while((c=fgetc(fp1))!=EOF){
            if(c>='a'&&c<='z') c=toupper(c);

            fputc(c,fp2); // write content to file2
            putchar(c); // display file on the screen
        }
        printf("\n");
    }
    fclose(fp1);
    fclose(fp2);



    return 0;
}

