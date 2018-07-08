#include<stdio.h>
int search(int* a,int start,int end,int X);
int main(){
    srand(time(NULL));
    int X=rand()%21;
    printf("X=%d\n",X);
    int i,n ;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    for(i=0;i<10;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }

    n=search(a,0,9,X);
    if(n==X) printf("YES\n");
    else printf("NO\n");
    return 0;
}

int search(int* a,int start,int end,int X){
    if(start==end){
        if(a[start]==X) return a[start];
        else return -1;
    }
    else{
        int mid;
        mid=(int)(start+end)/2;
        printf("mid=%d\n a[%d]=%d\n",mid,mid,a[mid]);
        if(a[mid]==X) return a[mid];
        else if(a[mid]>X) return search(a,start,mid-1,X);
        else return search(a,mid+1,end,X);
    }

}
