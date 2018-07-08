#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct phone{
    char model[MAX];
    int ROM;
    float screen;
    long unsigned int price;
}phone_t;

typedef struct  list_el{
	phone_t phone;
	struct list_el *next;
}node_phone;

node_phone *root,*cur,*prev;

void clear_buffer(){
	int ch;
	while((ch=getchar())!= '\n' && ch != EOF);
}

node_phone* makeNewNode(phone_t phone){
	node_phone *new;
	new=(node_phone*)malloc(sizeof(node_phone));
	new->phone=phone;
	new->next=NULL;
	return new;
}

phone_t readNode(FILE* fp){
	phone_t phone;
	fscanf(fp,"%s %d %f %lu",phone.model,&(phone.ROM),&(phone.screen),&(phone.price));
	return phone;
}

void display(node_phone* p){
	if(p==NULL){
		printf("the pointer is NULL");
		exit(1);
	}
	printf("%-25s %10d  %10.1f  %20lu \n",(p->phone).model,(p->phone).ROM,(p->phone).screen,(p->phone).price);
}

void insertAtHead(phone_t phone){

	node_phone *newNode;
   	newNode=makeNewNode(phone);
  	newNode->next=root;
   	root=newNode;
   	cur=root;
}

void insertAfterCurrent(phone_t phone){
	node_phone *new=makeNewNode(phone);
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

void insertBeforeCurrent(phone_t phone){
	node_phone *new=makeNewNode(phone);
    if(root==NULL){
		root=new;
		cur=root;
	}
	else{
        new->next=cur;
        prev->next=new;
        cur=prev->next;
	}
}

void travelsinglist(){
	node_phone *p=root;
	if(p==NULL) printf("The LIST is EMPTY\n");
	else{
        for(p=root;p!=NULL;p=p->next){
            display(p);
        }
	}
}

void freeallnode(){
    node_phone *to_free=root;
    while(to_free !=NULL){
        root=root->next;
        free(to_free);
        to_free =root;
    }
}

int main(){
    phone_t *p=NULL;
    FILE *fp,*fp2;
    char s[MAX];
    int i,num=0;
    int choice;

    do{
        printf("MENU \n1. Import data from TEXT file (insert At Head) \n2. Import data from DAT file (insert After Current) \n3. Display list (in line) \n4. Search \n5. Search phone under inputted \n6. Export to DAT file \n7. Exit \n");
        printf("please enter the function you want to execute: ");
        scanf("%d",&choice);
        printf("\n");

        while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6 && choice!=7){
            printf("Wrong input, please try again \n");
            break;
        }

        switch (choice){
            case 1:{
                freeallnode();
                num=0;
                if((fp=fopen("31model.txt","r+"))==NULL){
                    printf("cannot open file1!");
                    exit(1);
                }
// open file
                else{
                    while(fgets(s,MAX,fp)!=NULL){
                        num++;
                    }

                    if(fseek(fp,0,SEEK_SET)!=0){
                        printf("fseek failed");
                        exit(1);
                    }

                    for(i=0;i<num;i++){
                        phone_t phone;
                        phone=readNode(fp);
                        insertAtHead(phone);
                    }

                    travelsinglist();
                    fclose(fp);
                }
            }
                break;

            case 2:{
                if((fp2=fopen("31biphone.dat","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
// open file
                else{
                    freeallnode();

                    if(fseek(fp2,0,SEEK_SET)!=0){
                        printf("fseek failed");
                        exit(1);
                    }

                    phone_t *p1;
                    p1=(phone_t*)malloc(num*sizeof(phone_t));
                    if(p1==NULL){
                        printf("memory allocation failed");
                        exit(1);
                    }
                    fread(p1,sizeof(phone_t),num,fp2);

                    for(i=0;i<num;i++){
                        phone_t phone=*(p1+i);
                        insertAfterCurrent(phone);
                    }

                    travelsinglist();
                    fclose(fp2);
                    free(p1);
                }
            }
                break;

            case 3:{
                travelsinglist();
            }
                break;

            case 4:{
                char model[MAX]="";
                clear_buffer();
                printf("Please enter the model you want to search: ");
                gets(model);
                int check=0;
                node_phone *p;
                for(p=root;p!=NULL;p=p->next){
                    if(strcmp(model,(p->phone).model)==0){
                        display(p);
                        printf("\n");
                        check=1;
                    }
                }
                if(check==0){
                    printf("There doesnt exist this model\n\n");
                    break;
                }
            }
                break;

            case 5:{
                long int value;
                clear_buffer();

                do{
                    printf("Please enter the value you want to search:(>0) ");
                    scanf("%ld",&value);
                }while(value<=0);

                int check=0;
                node_phone *p;
                for(p=root;p!=NULL;p=p->next){
                    if(((p->phone).price)<=value){
                        display(p);
                        check=1;
                    }
                }
                if(check==0){
                    printf("There doesnt exist this model\n\n");
                    break;
                }

            }
                break;

            case 6:{
                FILE *fp3;
                if((fp3=fopen("31phonell.dat","r+b"))==NULL){
                    printf("cannot open file3!");
                    exit(1);
                }
                int count=0;
                node_phone *p;
                for(p=root;p!=NULL;p=p->next){
                    int irc=fwrite(p,sizeof(node_phone),1,fp3);
                    count +=irc;
                }
                printf("Export successfully %d model into DAT file\n",count);

                freeallnode();
                if(fseek(fp3,0,SEEK_SET)!=0){
                    printf("fseek failed");
                    exit(1);
                }
                node_phone *p2;
                p2=(node_phone*)malloc(count*sizeof(node_phone));
                    if(p2==NULL){
                        printf("memory allocation failed");
                        exit(1);
                    }
                int irc1=fread(p2,sizeof(node_phone),count,fp3);
                printf("return code=%d\n",irc1);
                for(i=0;i<irc1;i++){
                    phone_t phone=(p2+i)->phone;
                    insertAfterCurrent(phone);
                }
                travelsinglist();
                free(p2);
                fclose(fp3);
                freeallnode();
            }
                break;

            case 7: exit(0);
                break;
            default: break;

        }
    }while(choice!=7);
    return 0;
}


