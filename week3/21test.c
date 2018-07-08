#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(){
    char s[MAX]="";
    char c;
    int i,d;
    scanf("%d",&d);
    fflush(stdin);
    gets(s);
    for(i=0;i<strlen(s);i++){
        c=s[i];

    if(d<-25) d=d%26;
            if(c>='a' && c<='z'){
                if((c+d)<'a') c='z'+c+d-'a'+1;
                else c=c+d;
            }
            else if(c>='A' && c<='Z'){
                if((c+d)<'A') c='Z'+c+d-'A'+1;
                else c=c+d;
            }
            putchar(c);
    }
    return 0;
}
