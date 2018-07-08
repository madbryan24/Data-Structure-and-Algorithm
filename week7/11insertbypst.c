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

student_t readNode(){
	student_t student;
	clear_buffer();
	printf("please enter stt: ");
	scanf("%d",&student.stt);
	clear_buffer();
	printf("please enter mssv: ");
	gets(student.mssv);
   	printf("please enter name: ");
	gets(student.ten);
   	printf("please enter sdt: ");
	gets(student.sdt);
	printf("please enter diem: ");
	scanf("%f",&student.diem);
	return student;
}

void display(node* p){
	if(p==NULL){
		printf("the pointer is NULL");
		exit(1);
	}
	printf("%2d %10s %-10s %-15s %5.1f \n",(p->student).stt,(p->student).mssv,(p->student).ten,(p->student).sdt,(p->student).diem);
}

void insertAtHead(student_t student){

	node *newNode;
   	newNode=makeNewNode(student);
  	newNode->next=root;
   	root=newNode;
   	cur=root;
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

node* insertAtPosition(node* root,student_t student,int pst){
    node *p1;
    int count=0;
    if(pst==0){
            insertAtHead(student);
    }
    else{
        for(p1=root;p1!=NULL;p1=p1->next){
            cur=p1;
            count++;
            if(count==pst) break;
        }
        insertAfterCurrent(student);
    }
    return cur;
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


int main(){
    student_t *p=NULL;
    FILE *fp1;
    int i;
    int pst;
    int irc;
    if((fp1=fopen("21grade.dat","r+b"))==NULL){
        printf("cannot open file1!");
        exit(1);
    }
    else{
        p=(student_t*)malloc(MAX*sizeof(student_t));
        if(p==NULL){
            printf("memory allocation failed");
            exit(1);
        }
        irc=fread(p,sizeof(student_t),MAX,fp1);
        printf("irc=%d\n",irc);

        for(i=0;i<irc;i++){
            student_t student=*(p+i);
            insertAfterCurrent(student);
        }
        travelsinglist();
// load list from file
        do{
        printf("please enter the position you want to insert:(pst>=0) ");
        scanf("%d",&pst);
        }while(pst<-1);
        student_t student =readNode();
        node* new=insertAtPosition(root,student,pst);

        travelsinglist();
        free(p);
        fclose(fp1);
        freeallnode();
    }
    return 0;
}
