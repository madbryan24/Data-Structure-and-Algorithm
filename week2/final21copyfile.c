#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
int main(int argc,char* argv[]){
    while(argc!=3 && argc !=2){
        printf("the number of arguments should be 2 or 3!");
        exit(1);
    }
    if(argc==3){
        // kiem tra so doi so
        FILE *fp1,*fp2;
        char file1[MAX]="";
        char file2[MAX]="";
        char s1[MAX]="";
        char s2[MAX]="";

        char c;
        strcat(file1,argv[1]);
        strcat(file2,argv[2]);
        // gan gia tri doi so vao ten file

        if((fp1=fopen(file1,"r+"))==NULL){
            printf("Cannot open file1!");
            exit(1);
        }
        else if((fp2=fopen(file2,"r+"))==NULL){
            printf("Cannot open file2!");
            exit(1);
        }
        else{

            while((c=fgetc(fp1))!=EOF){
                fputc(c,fp2); // write content to file2
            }
            printf("\n");
            fseek( fp1, 0, SEEK_SET );
            fgets(s1,MAX,fp1);
            printf("the content of file1 after copied is: %s\n",s1);
            fseek( fp2, 0, SEEK_SET );
            fgets(s2,MAX,fp2);
            printf("the content of file2 after copied is: %s\n",s2);
            // xem noi dung cua 2 file sau khi cpoy
        }
        fclose(fp1);
        fclose(fp2);
    }
    else if(argc==2){
        if(strcmp(argv[1],"help")==0)
        {
            printf("The structure of this command line\n mycp file1 file2 \n");
        }
    }
    return 0;
}

