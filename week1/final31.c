#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int giaithua(int n){
    int i,gt=1;
    for(i=1;i<=n;i++){
        gt *=i;
    }
    return gt;
}
int main(int argc,char* argv[]){
    // kiem tra so doi so
    while(argc!=3 && argc != 4){
        printf("argc should be 3 or 4!");
        return 1;
    }
    // khai bao doi so
    int x,n=0;
    float ex,lim;
    char c;
    c=atof(argv[1]);
    x=atof(argv[2]);
    lim=atof(argv[3]);
    //tinh e mu x
    if(argc=3){
        ex=exp(x);
        printf("%f \n",ex);
    }
    else if(argc=4){
        while((float)(pow(x,n)/giaithua(n))>lim){
            ex += (float)pow(x,n)/giaithua(n);
            n++;
        }
        printf("%f and n= %d \n",ex,n);
    }

    return 0;
}
