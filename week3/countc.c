#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main(){
    FILE* fp;
    char c;
    int count=0;
    //gan gia tri doi so
    if((fp=fopen("count.txt","r"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else{
        printf("open file successfully\n\n");
        while((c=fgetc(fp))!=EOF){
                count++;
            putchar(c);
        }

        printf("\n%d\n",count);
    }

    fclose(fp);
    return 0;
}
