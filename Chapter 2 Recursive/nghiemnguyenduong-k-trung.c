#include<stdio.h>
#define MAX 100
int n;
int m;
int f;
int x[MAX];
int a[MAX];
int check(int v,int k){
    if(f<m) return 1;
    else return -1;
}
int finalcheck(){
    if(f==m) return 1;
}
void printSolution(){
    int i;
    for(i=1;i<=n;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
void TRY(int k){
    int v;
    for(v=1;v<=m-(n-k)-f;v++){

        if(a[v]==0){
            a[v]=1;
            if(check(v,k)){
                x[k]=v;
                f += v;
                if(k==n){
                    if(finalcheck()) printSolution();
                }
                else TRY(k+1);
            }
        a[v]=0;
        f -= v;
        }

    }
}
int main(){
    int i;
    f=0;
    m=13;
    n=3;
    for(i=1;i<=m;i++) a[i]=0;
    TRY(1);
}
