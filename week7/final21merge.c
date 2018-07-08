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

node *root,*root2,*cur,*prev,*cur2,*prev2;

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

void insertAfterCurrent2(student_t student){
	node *new=makeNewNode(student);
	if(root2==NULL){
		root2=new;
		cur2=root2;
	}
	else{
		new->next=cur2->next;
		cur2->next=new;
		prev2=cur2;
		cur2=cur2->next;
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

void travelsinglist2(){
	node *p=root2;
	if(p==NULL) printf("the list is EMPTY\n");
	else{
        for(p=root2;p!=NULL;p=p->next){
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

void freeallnode2(){
    node *to_free=root2;
    while(to_free !=NULL){
        root2=root2->next;
        free(to_free);
        to_free =root2;
    }
}

int main(int argc,char* argv[]){
    while(argc!=4){
        printf("The number of arguments should be 4");
        exit(1);
    }
    char filename1[MAX]="";
    char filename2[MAX]="";
    char filename3[MAX]="";
    strcat(filename1,argv[3]);
    strcat(filename2,argv[1]);
    strcat(filename3,argv[2]);
    node *p1,*p2,*p;
    FILE *fp1,*fp2,*fp3;
    int i,n,count=0;
    int pst;
    int irc;
    if((fp1=fopen(filename1,"r+b"))==NULL){
        printf("cannot open file1!");
        exit(1);
    }
    else if((fp2=fopen(filename2,"r+b"))==NULL){
        printf("cannot open file2!");
        exit(1);
    }
    else if((fp3=fopen(filename3,"r+b"))==NULL){
        printf("cannot open file3!");
        exit(1);
    }
    else{
        p1=(node*)malloc(MAX*sizeof(node));
        if(p1==NULL){
            printf("memory allocation failed");
            exit(1);
        }
        int irc1=fread(p1,sizeof(node),MAX,fp2);
        printf("return code file1 =%d\n",irc1);
        for(i=0;i<irc1;i++){
            student_t student=(p1+i)->student;
            insertAfterCurrent(student);
        }
        printf("LIST1\n");
        travelsinglist();

        p2=(node*)malloc(MAX*sizeof(node));
        if(p2==NULL){
            printf("memory allocation failed");
            exit(1);
        }
        int irc2=fread(p2,sizeof(node),MAX,fp3);
        printf("return code file2 =%d\n",irc2);
        for(i=0;i<irc2;i++){
            student_t student=(p2+i)->student;
            insertAfterCurrent2(student);
        }
        printf("LIST2\n");
        travelsinglist2();
// see file before merging
        for(p=root;p!=NULL;p=p->next){
            cur=p;
        }
        cur->next=root2;
        printf("the list after MERGING\n");
        travelsinglist();

        for(p=root;p!=NULL;p=p->next){
            int irc=fwrite(p,sizeof(node),1,fp1);
            count +=irc;
        }
        printf("MERGING successfully %d into DAT file 1\n",count);
//merge 2 lists into 1 list


        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        free(p1);
        free(p2);
        freeallnode();
        freeallnode2();
    }
    return 0;
}
