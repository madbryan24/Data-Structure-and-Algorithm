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

node_addr* makeNewNode(address addr){
	node_addr *new;
	new=(node_addr*)malloc(sizeof(node_addr));
	new->addr=addr;
	new->next=NULL;
	return new;
}

address readNode(){
	address addr;
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
int main(){
	node_addr *root,*cur;
	address addr;
	addr=readNode();
	root=makeNewNode(addr);
	cur=root;
	display(root);
	return 0;
}
