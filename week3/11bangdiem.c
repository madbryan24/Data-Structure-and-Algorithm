#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct student{
    int stt;
    char mssv[MAX];
    char ten[MAX];
    char sdt[MAX];
    float diem;
}student_t;

int main(){
    student_t *p;
    int n;
    FILE *fp;
    if((fp=fopen("file11.txt","r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    // mo file
    else{
        fcanf("");
    }
    return 0;
}
