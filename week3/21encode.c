#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main(int argc,char* argv[]){
    while(argc!=3){
        printf("the number of arguments should be 3!");
        exit(1);
    }
    FILE* fp;
    char filename[MAX]="";
    char c;
    int d,i=0;
    char s1[MAX]="";
    strcat(filename,argv[1]);
    d=atof(argv[2]);
    if(d<0){
        printf("the number should be positive!");
        exit(1);
    }
    //gan gia tri doi so
    if((fp=fopen(filename,"r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        printf("open file successfully\n\n");
        if(d>25) d=d%26;
        while((c=fgetc(fp))!=EOF){
            if(c>='a' && c<='z'){
                if((c+d)>'z') c='a'+c+d-'z'-1;
                else c=c+d;
            }
            else if(c>='A' && c<='Z'){
                if((c+d)>'Z') c='A'+c+d-'Z'-1;
                else c=c+d;
            }
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
