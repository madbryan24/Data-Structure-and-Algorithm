#include<stdio.h>
#include<stdlib.h>
typedef struct address_t{
	char name[20];
	char tel[11];
	char email[25];
}address;

typedef struct  list_el{
	address addr;
	struct list_el *next;
}node_addr;

node_addr *root,*cur,*prev;

void clear_buffer(){
	int ch;
	while((ch=getchar())!= '\n' && ch != EOF);
}

node_addr* makeNewNode(address addr){
	node_addr *new;
	new=(node_addr*)malloc(sizeof(node_addr));
	new->addr=addr;
	new->next=NULL;
	return new;
}

address readNode(){
	address addr;
	clear_buffer();
	printf("please enter name: ");
	gets(addr.name);
   	printf("please enter tel: ");
	gets(addr.tel);
   	printf("please enter email: ");
	gets(addr.email);
	return addr;
}
void display(node_addr* p){
	if(p==NULL){
		printf("the pointer is NULL");
		exit(1);
	}
	printf("%s \t %s \t %s \n",(p->addr).name,(p->addr).tel,(p->addr).email);
}

void insertAtHead(address  addr){

	node_addr *newNode;
   	newNode=makeNewNode(addr);
  	newNode->next=root;
   	root=newNode;
   	cur=root;
}

void insertAfterCurrent(address addr){
	node_addr *new=makeNewNode(addr);
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

void insertBeforeCurrent(address addr){
	node_addr *new=makeNewNode(addr);
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
	node_addr *p=root;
	if(p==NULL) printf("The LIST is EMPTY\n");
	else{
        for(p=root;p!=NULL;p=p->next){
            display(p);
        }
	}
}

void freeallnode(){
    node_addr *to_free=root;
    while(to_free !=NULL){
        root=root->next;
        free(to_free);
        to_free =root;
    }
}

int main(){
    int choice;
    do{
        printf("MENU \n1. makeNewNode \n2. insertAtHead \n3. insertAfterCurrent \n4. insertBeforeCurrent \n5. Travelsinglist \n6. freeAllNode \n7. Exit \n");
        printf("please enter the function you want to execute: ");
        scanf("%d",&choice);
        printf("\n");

        while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6 && choice!=7){
            printf("Wrong input, please try again \n");
            break;
        }

        switch (choice){
            case 1:{
                address addr;
                addr=readNode();
                node_addr *new=makeNewNode(addr);
                display(new);

            }
                break;
            case 2:{
                int choice;
                address addr;
                do{
                    printf("Do you want to add a Node:(enter 0 to stop): ");
                    scanf("%d",&choice);

                    if(choice!=0){
                        addr=readNode();
                        insertAtHead(addr);
                    }
                }while(choice!=0);

                travelsinglist();
            }
                break;
            case 3:{
                int choice;
                address addr;
                do{
                    printf("Do you want to add a Node:(enter 0 to stop): ");
                    scanf("%d",&choice);

                    if(choice!=0){
                        addr=readNode();
                        insertAfterCurrent(addr);
                    }
                }while(choice!=0);

                travelsinglist();
            }
                break;
            case 4:{
                int choice;
                address addr;
                do{
                    printf("Do you want to add a Node:(enter 0 to stop): ");
                    scanf("%d",&choice);

                    if(choice!=0){
                        addr=readNode();
                        insertBeforeCurrent(addr);
                    }
                }while(choice!=0);

                travelsinglist();
            }
                break;
            case 5:{
                printf("all the info of the LIST: \n");
                travelsinglist();
            }
                break;
            case 6:{
                printf("The LIST before freeAllNode \n");
                travelsinglist();
                freeallnode();
                printf("The LIST after freeAllNode \n");
                travelsinglist();
            }
                break;
            case 7: exit(0);
                break;
            default: break;
        }
    }while(choice!=7);

    return 0;
}
 /*  	int choice;
   	address addr;
	do{
		printf("Do you want to add a Node:(enter 0 to stop): ");
		scanf("%d",&choice);

		if(choice!=0){
		  	addr=readNode();
		    insertAfterCurrent(addr);
		}
	}while(choice!=0);

	travelsinglist();

	return 0;
}
*/
