#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define MAX 1000

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

int main(){
    FILE *fp,*fp2;
    int choice;
    int start,finish;
    float duration;
    do{
        printf("MENU \n1. Copy by character \n2. Copy by line \n3. Copy by block\n4. Exit \n");
        printf("please enter the function you want to execute: ");
        scanf("%d",&choice);

        while(choice!=1 && choice!=2 && choice!=3 && choice!=4){
            printf("Wrong input, please try again \n");
            break;
        }

        switch (choice){
            case 1:{
                if((fp=fopen("41essay.txt","r+b"))==NULL){
                    printf("cannot open file1!");
                    exit(1);
                }
                else if((fp2=fopen("41bicode.txt","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
//open file
                char c;
                start=clock();
                while((c=fgetc(fp))!=EOF){
                    fputc(c,fp2);
                }
                finish=clock();
                duration=(float)(finish-start)/CLOCKS_PER_SEC;
                printf("The duration of Copying by character: %fs\n",duration);

                fclose(fp);
                fclose(fp2);
            }
                break;
            case 2:{
                if((fp=fopen("41essay.txt","r+b"))==NULL){
                    printf("cannot open file1!");
                    exit(1);
                }
                else if((fp2=fopen("41bicode.txt","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
//open file
                char s[MAX];
                start=clock();
                while(fgets(s,MAX,fp)!=NULL){
                    fputs(s,fp2);
                }
                finish=clock();
                duration=(float)(finish-start)/CLOCKS_PER_SEC;
                printf("The duration of Copying by character: %fs\n",duration);

                fclose(fp);
                fclose(fp2);
            }
                break;
            case 3:{
                if((fp=fopen("41essay.txt","r+b"))==NULL){
                    printf("cannot open file1!");
                    exit(1);
                }
                else if((fp2=fopen("41bicode.txt","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
//open file
                int sob;
                printf("please enter the size of block: ");
                scanf("%d",&sob);
                char s1[sob];

                start=clock();
                while(!feof(fp)){
                    fread(s1, sizeof(char), sob, fp);
                    fwrite(s1, sizeof(char), sob, fp2);
                }
                finish=clock();
                duration=(float)(finish-start)/CLOCKS_PER_SEC;
                printf("The duration of Copying by character: %fs\n",duration);

                fclose(fp);
                fclose(fp2);
            }
                break;
            case 4: exit(0);
                break;
            default: break;

        }
    }while(choice!=4);
    return 0;
}


