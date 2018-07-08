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

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

int main(){
    phone_t *p=NULL;
    FILE *fp,*fp2;
    char s[MAX];
    int i,num=0;
    int irc1=0,irc2=0;
    int choice;

    do{
        printf("MENU \n1. Convert to .DAT file\n2. Display file\n3. Print NOKIA database\n4. Search\n5. Exit \n");
        printf("please enter the function you want to execute: ");
        scanf("%d",&choice);

        while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5){
            printf("Wrong input, please try again \n");
            break;
        }

        switch (choice){
            case 1:{
                if((fp=fopen("31model.txt","r+b"))==NULL){
                    printf("cannot open file1!");
                    exit(1);
                }
                else if((fp2=fopen("31biphone.dat","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
// open file
                else{
                    while(fgets(s,MAX,fp)!=NULL){
                        num++;
                    }
                    printf("num= %d \n",num);
                    p=(phone_t*)malloc(num*sizeof(phone_t));
                    if(p==NULL){
                        printf("memory allocation failed");
                        exit(1);
                    }
//provide memory
                    if(fseek(fp,0,SEEK_SET)!=0){
                        printf("fseek failed");
                        exit(1);
                    }

                    for(i=0;i<num;i++){
                        fscanf(fp,"%s %d %f %lu",(p+i)->model,&((p+i)->ROM),&((p+i)->screen),&((p+i)->price)); // problem
                    }

                    irc2=fwrite(p,sizeof(phone_t),num,fp2);
                    if(irc2==num){
                        printf("TEXT TO FILE SUCCESSFULLY\n");
                    }
// write ro file
                    fclose(fp);
                    fclose(fp2);
                    free(p);
                }
            }
                break;
            case 2:{
                int po;
                int n;
                do{
                printf("Do you want to display from START of END(1 for START and 2 for END): ");
                scanf("%d",&po);
                }while(po != 1 && po !=2);
                do{
                    printf("How many models you want to display(n <= %d): ",num);
                    scanf("%d",&n);
                }while(n<=0 || n>num);
// choose to display
                if((fp2=fopen("31biphone.dat","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
                else{
                    p=(phone_t*)malloc(num*sizeof(phone_t));
                    if(p==NULL){
                        printf("memory allocation failed");
                        exit(1);
                    }
//provide memory
                    irc1=fread(p,sizeof(phone_t),num,fp2);
                    printf("return code: %d\n",irc1);
                    int i;
                    if(po==1){
                        for(i=0;i<n;i++){
                            printf("Phone %d\n",i+1);
                            printf("    Model %d: %s\n",i+1,p[i].model);
                            printf("    ROM %d: %d\n",i+1,p[i].ROM);
                            printf("    Screen %d: %f\n",i+1,p[i].screen);
                            printf("    Price %d: %d\n",i+1,p[i].price);
                        }
                    }
                    else if(po==2){
                        for(i=num-1;i>num-n-1;i--){
                            printf("Phone %d\n",i+1);
                            printf("    Model %d: %s\n",i+1,p[i].model);
                            printf("    ROM %d: %d\n",i+1,p[i].ROM);
                            printf("    Screen %d: %f\n",i+1,p[i].screen);
                            printf("    Price %d: %d\n",i+1,p[i].price);
                        }
                    }
                    fclose(fp2);
                    free(p);
                }
            }
                break;
            case 3:{
                if((fp2=fopen("31biphone.dat","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
                else{
                    p=(phone_t*)malloc(num*sizeof(phone_t));
                    if(p==NULL){
                        printf("memory allocation failed");
                        exit(1);
                    }
                }
                irc1=fread(p,sizeof(phone_t),num,fp2);
// memory and read file
                char s[MAX]="";
                int j;
                for(i=0;i<num;i++){
                    strcpy(s,p[i].model);
                    s[5]='\0';
                    if(strcmp(s,"nokia")==0){
                        printf("Phone %d\n",i+1);
                        printf("    Model %d: %s\n",i+1,p[i].model);
                        printf("    ROM %d: %d\n",i+1,p[i].ROM);
                        printf("    Screen %d: %f\n",i+1,p[i].screen);
                        printf("    Price %d: %d\n",i+1,p[i].price);
                    }
                }

            }
                break;
            case 4:{
                if((fp2=fopen("31biphone.dat","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
                else{
                    p=(phone_t*)malloc(num*sizeof(phone_t));
                    if(p==NULL){
                        printf("memory allocation failed");
                        exit(1);
                    }
                }
                irc1=fread(p,sizeof(phone_t),num,fp2);
// memory and read file
                char model[MAX]="";
                clear_buffer();
                printf("Please enter the model you want to search: ");
                gets(model);
                int check=0;
                for(i=0;i<num;i++){
                    if(strcmp(model,p[i].model)==0){
                        printf("Phone %d\n",i+1);
                        printf("    Model %d: %s\n",i+1,p[i].model);
                        printf("    ROM %d: %d\n",i+1,p[i].ROM);
                        printf("    Screen %d: %f\n",i+1,p[i].screen);
                        printf("    Price %d: %d\n",i+1,p[i].price);
                    }
                    check=1;
                }
                if(check==0){
                    printf("There doesnt exist this model\n\n");
                    break;
                }
            }
                break;
            case 5: exit(0);
                break;
            default: break;

        }
    }while(choice!=5);




        /*
        if(fseek(fp2,0,SEEK_SET)!=0){
            printf("fseek failed");
            exit(1);
        }
        irc1=fread(p,sizeof(phone_t),num,fp2);
        printf("read code: %d\n",irc1);
        for(i=0;i<irc1;i++){
            printf("Phone %d\n",i+1);
            printf("    Model %d: %s\n",i+1,p[i].model);
            printf("    ROM %d: %d\n",i+1,p[i].ROM);
            printf("    Screen %d: %f\n",i+1,p[i].screen);
            printf("    Price %d: %d\n",i+1,p[i].price);
        }


    }
    */

    return 0;
}
