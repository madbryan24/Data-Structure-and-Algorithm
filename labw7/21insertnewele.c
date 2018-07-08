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

	node_addr *root,*cur;

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

void travelsinglist(){
	node_addr *p;
	for(p=root;p!=NULL;p=p->next){
		display(p);
	}
}
int main(){
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

	return 0;
}
