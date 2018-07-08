
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

typedef struct  list_el{
	student_t student;
	struct list_el *next;
}node;

node *root,*cur,*prev;

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

node* makeNewNode(student_t student){
	node *new;
	new=(node*)malloc(sizeof(node));
	new->student=student;
	new->next=NULL;
	return new;
}

void display(node* p){
	if(p==NULL){
		printf("the pointer is NULL");
		exit(1);
	}
	printf("%2d %10s %-10s %-15s %5.1f \n",(p->student).stt,(p->student).mssv,(p->student).ten,(p->student).sdt,(p->student).diem);
}


void insertAfterCurrent(student_t student){
	node *new=makeNewNode(student);
	if(root==NULL){
		root=new;
		cur=root;
	}
	else{
		new->next=cur->next;
		cur->next=new;
		prev=cur;
		cur=cur->next;
	}
}

void travelsinglist(){
	node *p=root;
	if(p==NULL) printf("the list is EMPTY\n");
	else{
        for(p=root;p!=NULL;p=p->next){
            display(p);
        }
	}
}


void freeallnode(){
    node *to_free=root;
    while(to_free !=NULL){
        root=root->next;
        free(to_free);
        to_free =root;
    }
}

int main(int argc,char* argv[]){
    while(argc!=2){
        printf("The number of arguments should be 2");
        exit(1);
    }
    FILE *fp1;
    node *p2;
    int i;
    char filename[MAX]="";
    strcat(filename,argv[1]);
    if((fp1=fopen(filename,"r+b"))==NULL){
        printf("cannot open file1!");
        exit(1);
    }
    else{
        p2=(node*)malloc(MAX*sizeof(node));
        if(p2==NULL){
            printf("memory allocation failed");
            exit(1);
        }
//providing memory
        int irc1=fread(p2,sizeof(node),MAX,fp1);
        printf("return code  =%d\n",irc1);
        for(i=0;i<irc1;i++){
            student_t student=(p2+i)->student;
            insertAfterCurrent(student);
        }
        printf("LIST\n");
        travelsinglist();

        fclose(fp1);
        free(p2);
        freeallnode();
    }
    return 0;
}

