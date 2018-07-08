#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char* subStr(char* s,int offset,int n){

    }
}

int main(){
    char s[MAX]="";
    int offset,n;
    printf("please enter a string:\n");
    fgets(s,MAX,stdin);

    printf("The substring starts from the offset number: ");
    scanf("%d",&offset);
    printf("The substring has the number of characters is: ");
    scanf("%d",&n);

////////////////////////////////////////////

    char *p=NULL;
    int i;
    int countoff=0,cnt=0,countc=0;
    char c;
    p=(char*)malloc(MAX*sizeof(char));

    for(i=0;i<strlen(s);i++){
        if(s[i]=' ') countoff++;
    }
    printf("count off = %d\n",countoff);

    if(offset > countoff){
        printf("the offset invalid");
        exit(0);
    }
    else{
        for(i=0;i<strlen(s);i++){
            if(s[i]=' '){
                if(countoff < offset) cnt++;
            }
            if(cnt == offset){
                if(countc < n){
                    countc++;
                    *(p+i)=s[i];
                }
                else break;
            }
        }
        if(countc < n){
            printf("the number of characters left must be less than %d \n",n);
            exit(0);
        }

///////////////////////////////////////////////

    for(i=0;i<n;i++){
        printf("%c",*(p+i));
    }
    return 0;
}

