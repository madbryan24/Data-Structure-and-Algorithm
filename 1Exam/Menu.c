#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

int main(){
    int choice;
    do{
        printf("MENU \n1.\n2.\n3.\n4.\n5.\n6. Exit \n");
        printf("please enter the function you want to execute: ");
        scanf("%d",&choice);
        printf("\n");

        while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6){
            printf("Wrong input, please try again \n");
            break;
        }

        switch (choice){
            case 1:{
            }
                break;

            case 2:{
            }
                break;

            case 3:{
            }
                break;

            case 4:{
            }
                break;

            case 5:{
            }
                break;

            case 6: exit(0);
                break;

            default: break;
        }
    }while(choice!=6);

    return 0;
}
