#include<stdio.h>
#include<stdlib.h>
typedef struct songuyen{
    int dulieu;
    struct songuyen *tiep;
}songuyen_t;

typedef struct list{
    songuyen_t *head;
    songuyen_t *tail;
}
songuyen_t* taosonguyen(songuyen_t *p){
    songuyen_t *check;
    check=p;
    int choice;

    do{
        if(check==NULL){
            check=(songuyen_t*)malloc(1*sizeof(songuyen_t));
        }
        else{
            while((check->tiep)!=NULL) check=check->tiep;
            check->tiep=(songuyen_t*)malloc(1*sizeof(songuyen_t));
            check=check->tiep;
        }
        printf("please enter the value of the list: ");
        scanf("%d",&(check->dulieu));
        check->tiep=NULL;
        printf("Do you want to add more data: ");
        scanf("%d",&choice);
    }while(choice!=0);
    return check;
}

void insonguyen(songuyen_t* check){
    while(check!=NULL){
        printf("%d\t",check->dulieu);
        check=check->tiep;
    }
}
int main(){
    printf("sizeof(songuyen_t)=%d bytes \n",sizeof(songuyen_t));
    songuyen_t *p=NULL;
    songuyen_t *check=taosonguyen(p);
    insonguyen(check);
    return 0;
}

