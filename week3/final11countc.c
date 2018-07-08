#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100

int main(){
    char list[MAX];
    int count[MAX]={0};
    FILE *fp;
    char c='\0';
    int i,n=1,check=0;
    if((fp=fopen("21vnedict.txt","r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    // mo file
    else{
        printf("open file successfully\n\n");
        c=fgetc(fp);
        putchar(c);
        list[0]=c;
        count[0]=1;
        while((c=fgetc(fp))!=EOF){
            putchar(c);
            if(c==' ' || c=='\n') continue; // bo qua dau cach va enter
            if(isupper(c)) c=tolower(c);

            for(i=0;i<n;i++){
                if(list[i]==c){
                 count[i]++;
                 check=1;
                }
            }
            //check xem ky tu da duoc dem chua
            if(check==0){
                list[n]=c;
                count[n]++;
                n++;
            }
            //them ky tu chua dem vao mang
            check=0;
        }
        printf("\n");
        for(i=0;i<n;i++){
            if(count[i]>0)
                printf("character |%c| appears %d time(s)\n",list[i],count[i]);
        }
    }
    fclose(fp);
    return 0;
}
