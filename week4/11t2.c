#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct student{
    int stt;
    char mssv[MAX];
    char ten[MAX];
    char sdt[MAX];
    float diem;
}student_t;

int main(){
    printf("size of st is: %d\n",sizeof(student_t));
    student_t *p,list[50];
    p=list;
    int i,n;
    FILE *fp,*fp2;
    if((fp=fopen("11danhsach.txt","r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    else if((fp2=fopen("11bangdiem.txt","r+"))==NULL){
        printf("cannot open file!");
        exit(1);
    }
    // mo file
    else{
        printf("the number of students: ");
        scanf("%d",n);
        for(i=0;i<n;i++){
            fscanf(fp,"%d %s %s %s",&((p+i)->stt),(p+i)->mssv,(p+i)->ten,(p+i)->sdt);
        }
        printf("please enter the scores of students");
        for(i=0;i<n;i++){
            printf("score[%d]=",i);
            scanf("%f",&((p+i)->diem));
        }

        fseek(fp,0,SEEK_SET);
        for(i=0;i<n;i++){
            fprintf(fp2,"%d %s %s %s %f",(p+i)->stt,(p+i)->mssv,(p+i)->ten,(p+i)->sdt,(p+i)->diem);
        }
    }

    return 0;
}

