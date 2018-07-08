#include<stdio.h>
#define MAX 100
int x[MAX];
int k;
int n;
int m;
int f;
int count;
int check(int v,int k){
    if(f<=m) return 1;
    else return -1;
}
int finalCheck(){
    if(f == m) return 1;
}
void printSolution(){
    int i;
    count++;
    printf("config %d: ",count);
    for(i=1;i<=n;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
void TRY(int k){
    int v;
    for(v=0;v<=1;v++){
            if(check(v,k)){
               x[k]=v;
               f += v;
            }
        if(k==n){
            if(finalCheck()==1)
                printSolution();
        }
        else{
            TRY(k+1);
        }

    }
}

int main(){
    count =0;
    n=5;
    m=3;
    TRY(1);
    return 0;
}

