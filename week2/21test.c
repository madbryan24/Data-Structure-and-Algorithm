#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp1,*fp2;
    char c;
    char file1[50]="file1.txt";
    char file2[50]="file2.txt";
    if((fp1=fopen(file1,"r"))==NULL){
        printf("Cannot open file1!");
        exit(1);
    }
    else if((fp2=fopen(file2,"w"))==NULL){
        printf("Cannot open file2!");
        exit(1);
    }
    else{
        printf("open file successfully\n\n");
        while((c=fgetc(fp1))!=EOF){
        fputc(c,fp2); // write content to file2
        putchar(c); // display file on the screen
        }
        printf("\n");
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
