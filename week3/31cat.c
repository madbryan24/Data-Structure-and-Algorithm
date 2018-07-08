#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}
int main(int argc,char* argv[]){
    while(argc!=2 && argc!=3){
        printf("the number of arguments should be 2 or 3!");
        exit(1);
    }
    FILE* fp;
    char s[MAX]="";
    char filename[MAX]="";
    int count=0;
    char c,m;
    strcat(filename,argv[1]);

    if((fp=fopen(filename,"r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        printf("open file successfully\n\n");
        if (argc==2){
            while ((c = fgetc(fp)) != EOF)
            putchar(c);
        }
        else if(argc==3){
        do{
            m=getchar();
            if(m=='\n'){
                while((c=fgetc(fp))!=EOF){
                    putchar(c); count++;
                    if(count==84){
                        printf("\n");
                        count=0;
                        break;
                    }
                }
            }
            else fseek(fp,-1,SEEK_CUR);
        }while((c=fgetc(fp))!=EOF);
        }
    }
    fclose(fp);
    return 0;
}
