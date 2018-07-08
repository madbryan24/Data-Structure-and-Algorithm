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
    student_t *p=NULL;
    int n;
    printf("the number of students: ");
    scanf("%d",&n);
    p=(student_t *)malloc(n*sizeof(student_t));
    if(p==NULL){
        printf("failed to provide memories");
        exit(0);
    }
    else printf("providing memories successfully");
    free(p);

    return 0;
}

