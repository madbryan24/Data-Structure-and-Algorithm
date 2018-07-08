#include<stdio.h>

int n;
int x[100];

int check(int v,int k){
    int i;
    for(i=1;i<k;i++){
        if(x[i]==v) return -1;
    }
    return 1;
}

void printSolution(){
    int i;
    for(i=1;i<=n;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}

void TRY(k){
    int v;
    for(v=1;v<=n;v++){
        x[k]=v;
        if(check(v,k)==1){
            if(k==n) printSolution();
            else TRY(k+1);
        }
    }
}

int main(){
    n=4;
    TRY(1);
    return 0;
}

