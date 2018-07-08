#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
int main(int argc,char* argv[]){
    while(argc != 2){
        printf("the number of arguments should be 2!");
        exit(1);
    }
    FILE *fp;
    char filename[MAX]="";
    strcat(filename,argv[1]);
    if((fp=fopen(filename,"r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        int i=0;
        printf("open file successfully!\n");
        char s[MAX]="";
        char s1[MAX]="";
        char c;
        while((c=fgetc(fp))!=EOF)
        {
            if(islower(c)) c=toupper(c);
            putchar(c);
            s1[i]=c;
            i++;
        }
        s1[i]='\0';
        fseek( fp, 0, SEEK_SET );
        fputs(s1,fp);
    }
    fclose(fp);



    return 0;
}
