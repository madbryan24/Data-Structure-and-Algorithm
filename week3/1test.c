#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

int main(){
    char list[MAX];
    int count[MAX]={0};
    FILE *fp;
    char c='\0';
    int i,n=0;
    if((fp=fopen("file11.txt","r"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    // mo file
    else{
        printf("open file successfully\n\n");
        while((c=fgetc(fp))!=EOF){
            if(c==' ' || c=='\n') continue;
            else if(isupper(c)) c=tolower(c);
                   list[n]=c;
                   count[n]++;
                   n++;
        }
        for(i=0;i<n;i++){
            if(count[i]>0)
                printf("character |%c| appears %d time(s)\n",list[i],count[i]);
        }
    }
    fclose(fp);
    return 0;
}
