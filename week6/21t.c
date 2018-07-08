#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500

typedef struct line{
    char content[MAX];
}line_t;

int main(){
    line_t *p=NULL,*p1=NULL;
    FILE *fp,*fp2;
    char s[MAX]="";
    int i,num=0;
    int irc1=0,irc2=0;
    clock_t start, finish;

    if((fp=fopen("22vnedict.txt","r"))==NULL){
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
        printf("num= %d \n",num);
        p=(line_t*)malloc(num*sizeof(line_t));
        if(p==NULL){
            printf("memory allocation failed");
            exit(1);
        }

        if(fseek(fp,0,SEEK_SET)!=0){
            printf("fseek failed");
            exit(1);
        }

        for(i=0;i<num;i++){
            fgets(s,MAX,fp);
            strcpy((p+i)->content,s);
        }

        irc2=fwrite(p,sizeof(line_t),num,fp2);
        if(irc2==num){
            printf("return code = %d \n",irc2);
            printf("CONVERT TO BINARY SUCCESSFULLY\n");
        }

        p1=(line_t*)malloc(num*sizeof(line_t));
        if(p==NULL){
            printf("memory allocation failed");
            exit(1);
        }

        if(fseek(fp2,0,SEEK_SET)!=0){
            printf("fseek failed");
            exit(1);
        }
        irc1=fread(p,sizeof(line_t),num,fp2);
        printf("read code: %d\n",irc1);

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
            printf("%s \n",(p+i)->content);
        }

        fclose(fp);
        fclose(fp2);
        free(p);
        free(p1);
    }
    return 0;
}
