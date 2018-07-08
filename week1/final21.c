#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

int main(){
    int i;
    char sentence[10][50];
    char article[5][10]={"the","a","one","some","any"};
    char noun[5][10]={"boy","girl","dog","town","car"};
    char verb[5][10]={"drove","jumped","ran","walked","skipped"};
    char preposition[5][10]={"to","from","over","under","on"};
    // tao ngau nhien theo thoi gian
    srand(time(NULL));
    // ghep ngau nhien thanh cau
    for(i=0;i<10;i++){
        strcpy(sentence[i],"");
        strcat(sentence[i],article[rand()%4]);
        strcat(sentence[i]," ");
        strcat(sentence[i],noun[rand()%4]);
        strcat(sentence[i]," ");
        strcat(sentence[i],verb[rand()%4]);
        strcat(sentence[i]," ");
        strcat(sentence[i],preposition[rand()%4]);
        strcat(sentence[i]," ");
        strcat(sentence[i],article[rand()%4]);
        strcat(sentence[i]," ");
        strcat(sentence[i],noun[rand()%4]);
        strcat(sentence[i],".");
    // chuyen chu dau thanh chu hoa
        sentence[i][0]=sentence[i][0]-32;
    // in ra
        printf("%d. %s\n",i+1,sentence[i]);
    }
    return 0;
}
