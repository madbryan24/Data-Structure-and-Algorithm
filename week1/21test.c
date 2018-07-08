#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

int main(){
    int i,n;
    char sentence[10][50];
    char article[5][10]={"the","a","one","some","any"};
    char noun[5][10]={"boy","girl","dog","town","car"};
    char verb[5][10]={"drove","jumped","ran","walked","skipped"};
    char preposition[5][10]={"to","from","over","under","on"};

    srand((unsigned) time(NULL));
    for(i=0;i<10;i++){
        n=rand()%4;
        strcat(sentence[i],article[n]);
        strcat(sentence[i]," ");
        n=rand()%4;
        strcat(sentence[i],noun[n]);
        strcat(sentence[i]," ");
        n=rand()%4;
        strcat(sentence[i],verb[n]);
        strcat(sentence[i]," ");
        n=rand()%4;
        strcat(sentence[i],preposition[n]);
        strcat(sentence[i]," ");
        n=rand()%4;
        strcat(sentence[i],article[n]);
        strcat(sentence[i]," ");
        n=rand()%4;
        strcat(sentence[i],noun[n]);
        strcat(sentence[i],".");
        sentence[i][0]=sentence[i][0]-32;

        printf("%s \n",sentence[i]);
    }
    return 0;
}
