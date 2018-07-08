#include <stdio.h>

int n;
int x[100];
int a[100];

void printSolution(){
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}
void TRY(int k){
    int v;
    for(v = 1; v <= n; v++){
        if(a[v]==0){
            a[v]=1;
            x[k] = v;
            if(k == n){
                printSolution();
            }else{
                TRY(k+1);
            }
            a[v]=0;// recover
        }
    }
}

int main(){
    n = 3;
    for (int i=0;i<=n;i++) a[i]=0;
    TRY(1);
}
