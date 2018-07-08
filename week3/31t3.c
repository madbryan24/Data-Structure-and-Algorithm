#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500
void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}
int main(int argc,char* argv[]){
    while(argc!=2){
        printf("the number of arguments should be 2!");
        exit(1);
    }
    FILE* fp;
    char s[MAX]="";
    char filename[MAX]="";
    int i=0,page=1;
    char c;
    strcat(filename,argv[1]);

    if((fp=fopen(filename,"r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        printf("open file successfully\n\n");
        do{
            if(page>1) fseek(fp,-21,SEEK_CUR);
            c=getchar();
            if(c=='\n'){
                for(i=0;i<24;i++){
                    if(fgets(s,MAX,fp)!=NULL)
                        puts(s);
                }
            }
            page++;
        }while(fgets(s,MAX,fp)!=NULL);
    }
    fclose(fp);
    return 0;
}

