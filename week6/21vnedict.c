#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct word{
    char eng[MAX];
    char viet[MAX];
}word_t;

int main(){
    word_t *p=NULL;
    FILE *fp,*fp2;
    char s[MAX];
    int i,num=0;
    int irc2=0;
    int start,end;

    if((fp=fopen("22t.txt","r+b"))==NULL){
        printf("cannot open file1!");
        exit(1);
    }
    else if((fp2=fopen("21bivnedict.dat","r+b"))==NULL){
        printf("cannot open file2!");
        exit(1);
    }
    else{
        while(fgets(s,MAX,fp)!=NULL){
            num++;
        }
        p=(word_t*)malloc(num*sizeof(word_t));
        if(p==NULL){
            printf("memory allocation failed");
            exit(1);
        }

        if(fseek(fp,0,SEEK_SET)!=0){
            printf("fseek failed");
            exit(1);
        }

        for(i=0;i<num;i++){
            fscanf(fp,"%s:%s",(p+i)->eng,(p+i)->viet);
            if(fscanf(fp,"%s:%s",(p+i)->eng,(p+i)->viet)==0){
                printf("fscanf failed");
                exit(1);
            }
        }


        irc2=fwrite(p,sizeof(word_t),num,fp2);
        if(irc2==num){
            printf("return code = %d \n",irc2);
            printf("CONVERT TO BINARY SUCCESSFULLY\n");
        }

        do{
            printf("START(0 <= start <= %d): ",num);
            scanf("%d",&start);
        }while(start<0 || start > num);

        do{
            printf("END(start < end <= %d): ",num);
            scanf("%d",&end);
        }while(end<=start || end > num);


        if(fseek(fp2,0,SEEK_SET)!=0){
            printf("fseek failed");
            exit(1);
        }
        for(i=start;i<end;i++){
            printf("%s : %s \n",(p+i)->eng,(p+i)->viet);
        }
        fclose(fp);
        fclose(fp2);
        free(p);
    }
    return 0;
}
