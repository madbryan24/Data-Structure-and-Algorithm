#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(int argc,char* argv[]){
    while(argc!=3){
        printf("the number of arguments should be 3!");
        exit(1);
    }
    FILE *fp,*fp2;
    char word[5][MAX]={"fuck","bitch","bastard","shit","damn"}; // them tu
    char s[MAX]="";
    char c;
    int i=0;

    char filename[MAX]="";
    strcat(filename,argv[1]);
    char sym;
    sym=argv[2][0];

    if((fp=fopen(filename,"r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else if((fp2=fopen("file21re2.txt","r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        printf("open file successfully!\n\n");
        while((c=fgetc(fp))!=EOF){
            if(c!=' ' && c!='\n'){
                s[i]=c;
                i++;
            }
            else{
                s[i]='\0';
                for(i=0;i<5;i++){
                    if((strcmp(s,word[i]))==0){
                        for(i=0;i<strlen(s);i++)
                            s[i]=sym;
                    }
                }
                printf("%s",s);
                putchar(' ');

                i=0;
            }
        }

        s[i]='\0';
        for(i=0;i<5;i++){
                if((strcmp(s,word[i]))==0){
                    for(i=0;i<strlen(s);i++)
                        s[i]=sym;
                }
        }
        printf("%s",s);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
