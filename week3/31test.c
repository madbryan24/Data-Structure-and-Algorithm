#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
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
    int i,count=0;
    char c,m;
    strcat(filename,argv[1]);

    if((fp=fopen(filename,"r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        printf("open file successfully\n\n");
        clear_buffer();
        do{
                m='\0';
                m=getchar();
                if(m=='\n'){
                        for(i=0;i<211*50;i++){
                            if((c=fgetc(fp))!=EOF){
                                putchar(c);
                                if(c=='\n') count++;
                                if(count==50) {
                                count=0;
                                continue;
                                }
                            }
                        }
                }
        }while((c=fgetc(fp))!=EOF);
    }
    fclose(fp);
    return 0;
}
