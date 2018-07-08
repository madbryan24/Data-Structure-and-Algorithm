#include<stdio.h>
int equality(int a1[],int a2[],int n){
  int i,j,check=1;
  for(i=0;i<n;i++){
    if(a1[j]!=a2[j]){
      check=0;
      break;
    }
  }
  if(check!=1){
    check=-1;
    for(i=0;i<n;i++){
      if(a1[j]!=a2[n-j-1]){
	check=0;
        break;
      }
    }
  }
  return check;
}
int main(){
  int i,n,check;
  int a1[100],a2[100];
  do{
    printf("please enter the value of n: ");
    scanf("%d",&n);
  }while(n<1 || n>100);
  for(i=0;i<n;i++){
    printf("a1[%d]= ",i);
    scanf("%d",&a1[i]);
  }
  for(i=0;i<n;i++){
    printf("a2[%d]= ",i);
    scanf("%d",&a2[i]);
  }
  check=equality(a1,a2,n);
  printf("the result is: %d \n",check);
  return 0;
}




