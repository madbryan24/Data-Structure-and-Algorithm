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

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

int main(){
    char s[MAX];
    student_t *p=NULL;
    FILE *fp,*fp2,*c;
    int irc1=0,irc2=0,num=0;

    if((fp=fopen("11bangdiem.txt","r+"))==NULL){
        printf("cannot open file1!");
        exit(1);
    }
    else if((fp2=fopen("11grade.txt","r+b"))==NULL){
        printf("cannot open file2!");
        exit(1);
    }

    while((c=fgets(s,MAX,fp))!=NULL){
        num++;
    }

    if(fseek(fp,0,SEEK_SET)!=0){
		printf("fseek failed");
		exit(1);
	}

    p=(student_t*)malloc(num*sizeof(student_t));
    if(p==NULL){
		printf("memory allocation failed");
		exit(1);
	}

	irc1=fread(p,sizeof(student_t),num,fp);
	printf("read code: %d\n",irc1);
    int choice;
    do{
        printf("MENU \n1. Text to file\n2. Display file\n3. Search and Update\n4. Exit \n");
        printf("please enter the function you want to execute: ");
        scanf("%d",&choice);

        while(choice!=1 && choice!=2 && choice!=3 && choice!=4){
            printf("Wrong input, please try again \n");
            break;
        }

        switch (choice){
            case 1:{
                }
                break;
            case 2:{
                }
                break;
            case 3:{
                }
                break;
            case 4:{
                }
                break;
            default: break;
        }
    }while(choice!=4);

    return 0;
}
