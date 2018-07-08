#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(int argc,char* argv[]){
    while(argc!=2){
        printf("the number of arguments should be 2!");
        exit(1);
    }
    int sym;
    sym=atoi(argv[1]);

        printf("sym is %d \n",sym);

    return 0;
}

