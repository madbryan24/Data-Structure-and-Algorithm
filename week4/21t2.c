#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(){
    FILE *fp;
    char word[5][MAX]={"fuck","bitch","bastard","shit","damn"}; // them tu
    char s[MAX]="";
    char c;
    int i=0;

    if((fp=fopen("file21re.txt","r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        printf("opesn file successfully!\n\n");
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
                            s[i]='*';
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
                        s[i]='*';
                }
        }
        printf("%s",s);
    }
    fclose(fp);
    return 0;
}


