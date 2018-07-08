#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char* subStr(char* s,int offset,int n){
    char *p=NULL;
    int i,j=0;
    int countc=0,cnt=0,countn=0;
    char c;
    p=(char*)malloc(MAX*sizeof(char));

    for(i=0;i<strlen(s)-1;i++){
        countc++;
    }
// vi fgets lay enter
    printf("count character = %d\n",countc);
// dem so ki tư trong chuoi
    if(offset > countc){
        printf("the offset invalid");
        exit(0);
    }
// checl offset
    else{
        j=countc-offset;
        if(j < n){
            printf("the number of characters left must be less than %d \n",n);
            exit(0);
        }
        else{
            for(i=0;i<strlen(s)-1;i++){
                if(cnt < offset){
                    cnt++;
                }
                else if(cnt == offset){
                    if(countn < n){
                        *(p+countn)=s[i];
                        countn++;
                    }
                }
            }
            *(p+countn)='\0';
        }
    }
    return p;
}

int main(){
    char *p=NULL;
    char s[MAX]="";
    int offset,i,n;
    p=(char*)malloc(MAX*sizeof(char));

    printf("please enter a string:\n");
    fgets(s,MAX,stdin);

    printf("The substring starts from the offset number: ");
    scanf("%d",&offset);
    printf("The substring has the number of characters is: ");
    scanf("%d",&n);

    p=subStr(s,offset,n);

    printf("the content of the substring is: \n");
    for(i=0;i<n;i++){
        printf("%c",*(p+i));
    }
    printf("\n");
    return 0;
}


