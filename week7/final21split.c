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
    while(argc!=5){
        printf("The number of arguments should be 5");
        exit(1);
    }
    char filename1[MAX]="";
    char filename2[MAX]="";
    char filename3[MAX]="";
    strcat(filename1,argv[1]);
    strcat(filename2,argv[3]);
    strcat(filename3,argv[4]);
    int pst;
    pst=atoi(argv[2]);
    student_t *p=NULL;
    node *p1;
    FILE *fp1,*fp2,*fp3;
    int i,count=0;
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
        p=(student_t*)malloc(MAX*sizeof(student_t));
        if(p==NULL){
            printf("memory allocation failed");
            exit(1);
        }
        irc=fread(p,sizeof(student_t),MAX,fp1);
        printf("irc=%d\n",irc);

        if(pst<=0 || pst >=irc){
            printf(" the position should be (0 < pst < %d) ",irc);
            exit(1);
        }

        for(i=0;i<irc;i++){
            student_t student=*(p+i);
            insertAfterCurrent(student);
        }
        travelsinglist();

// read file and put in linked list

        cur=root;
        for(p1=root;p1!=NULL;p1=p1->next){
            count++;
            prev=cur;
            cur=p1;
            if(count==pst){
                root2=p1;
                prev->next=NULL;
                break;
            }
        }
        printf("list1\n");
        travelsinglist();
        printf("list2\n");
        travelsinglist2();
// split two list
                count=0;
                node *p;
                for(p=root;p!=NULL;p=p->next){
                    int irc=fwrite(p,sizeof(node),1,fp2);
                    count +=irc;
                }
                printf("Export successfully %d into DAT file 2\n",count);

                int count1=0;
                for(p=root2;p!=NULL;p=p->next){
                    int irc=fwrite(p,sizeof(node),1,fp3);
                    count1 +=irc;
                }
                printf("Export successfully %d into DAT file 3\n",count1);
//write to file


    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    free(p);

    freeallnode();
    freeallnode2();
    }
    return 0;
}

