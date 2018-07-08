#include<stdio.h>
#include<stdlib.h>
int main(void){
  int i,n,*p;
  printf("How numbers do you want: ");
  scanf("%d",&n);

  p=(int *)malloc(n*sizeof(int));
  if(p==NULL){
    printf("Memory allocation failed!");
    return 1;
  }
  for(i=0;i<n;i++){
    printf("[i]= ");
    scanf("%d",&p[i]);
  }
  for(i=n-1;i>=0;i--){
    printf("%d ",p[i]);
  }
  printf("\n");
  free(p);
  return 0;
}
