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

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

int main(){
    student_t *p=NULL;
    FILE *fp,*fp2,*c;
    int irc1=0,irc2=0,num=0;
    char s[MAX];
    int i;
    int choice;

    do{
        printf("MENU \n1. Text to file\n2. Display file\n3. Search and Update\n4. Exit \n");
        printf("please enter the function you want to execute: ");
        scanf("%d",&choice);

        while(choice!=1 && choice!=2 && choice!=3 && choice!=4){
            printf("Wrong input, please try again \n");
            break;
        }

        switch (choice){
            case 1:{
                if((fp=fopen("11bangdiem.txt","r+b"))==NULL){
                    printf("cannot open file1!");
                    exit(1);
                }
                else if((fp2=fopen("11grade.dat","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
                else{
                    while(fgets(s,MAX,fp)!=NULL){
                        num++;
                    }

                    p=(student_t*)malloc(num*sizeof(student_t));
                    if(p==NULL){
                        printf("memory allocation failed");
                        exit(1);
                    }

                    if(fseek(fp,0,SEEK_SET)!=0){
                        printf("fseek failed");
                        exit(1);
                    }

                    for(i=0;i<num;i++){
                        fscanf(fp,"%d %s %s %s %f",&((p+i)->stt),(p+i)->mssv,(p+i)->ten,(p+i)->sdt,&(p+i)->diem);
                    }

                    irc2=fwrite(p,sizeof(student_t),num,fp2);
                    if(irc2==num){
                        printf("TEXT TO FILE SUCCESSFULLY\n");
                    }
                    fclose(fp);
                    fclose(fp2);
                    free(p);
                }
            }
                break;
            case 2:{
                if((fp2=fopen("11grade.dat","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
                p=(student_t*)malloc(num*sizeof(student_t));
                if(p==NULL){
                    printf("memory allocation failed");
                    exit(1);
                }
                irc1=fread(p,sizeof(student_t),num,fp2);
                printf("read code: %d\n",irc1);
                for(i=0;i<irc1;i++){
                    printf("Student %d\n",i+1);
                    printf("    STT %d: %d\n",i+1,p[i].stt);
                    printf("    MSSV %d: [%s]\n",i+1,p[i].mssv);
                    printf("    Ten %d: %s\n",i+1,p[i].ten);
                    printf("    Diem %d: %f\n",i+1,p[i].diem);
                }
                fclose(fp2);
                free(p);
            }
                break;
            case 3:{
                int check=0;
                float as;
                int irc3=0,irc4=0;
                char studentid[MAX];
                if((fp2=fopen("11grade.dat","r+b"))==NULL){
                    printf("cannot open file2!");
                    exit(1);
                }
                p=(student_t*)malloc(num*sizeof(student_t));
                if(p==NULL){
                    printf("memory allocation failed");
                    exit(1);
                }
                irc1=fread(p,sizeof(student_t),num,fp2);

                clear_buffer();
                printf("Please enter the student ID: ");
                scanf("%s",studentid);
                for(i=0;i<num;i++){
                    if(strcmp(studentid,p[i].mssv)==0){
                        printf("    STT %d: %d\n",i+1,p[i].stt);
                        printf("    MSSV %d: %s\n",i+1,p[i].mssv);
                        printf("    Ten %d: %s\n",i+1,p[i].ten);
                        printf("    Diem %d: %f\n",i+1,p[i].diem);
                        do{
                            printf("Please enter the alternative score for this student:(0.0<= score <= 10.0) ");
                            scanf("%f",&as);
                        }while(as<0.0 || as>10.0);
                        p[i].diem=as;
                        fseek(fp2,i*sizeof(student_t),SEEK_SET);
                        irc3=fwrite(p+i,sizeof(student_t),1,fp2);
                        if(irc3 != 0){
                            printf("UPDATE FILE SUCCESSFULLY\n");
                        }

                        fseek(fp2,i*sizeof(student_t),SEEK_SET);
                        irc4=fread(p+i,sizeof(student_t),1,fp2);
                        if(irc4 != 0){
                            printf("    STT %d: %d\n",i+1,p[i].stt);
                            printf("    MSSV %d: %s\n",i+1,p[i].mssv);
                            printf("    Ten %d: %s\n",i+1,p[i].ten);
                            printf("    Diem %d: %f\n",i+1,p[i].diem);
                        }
                    check=1;
                    }
                }
                if(check==0){
                    printf("Student ID invalid\n");
                    break;
                }

                fclose(fp2);
                free(p);
            }
                break;
            case 4: exit(0);
                break;
            default: break;
        }
    }while(choice!=4);

    return 0;
}
