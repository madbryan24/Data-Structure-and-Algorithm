#include<stdio.h>
#include<stdlib.h>
int main(void){
  int i,n,m,*p;
  printf("How numbers do you want: ");
  scanf("%d",&n);

  p=(int *)malloc(n*sizeof(int));
  if(p==NULL){
    printf("Memory allocation failed!");
    return 1;
  }
  for(i=0;i<n;i++){
    printf("[%d]= ",i);
    scanf("%d",&p[i]);
  }
  printf("\n");
  printf("How many elements do you want to add: ");
  scanf("%d",&m);
  p=(int *)realloc(p,m*sizeof(int));
  // add m memory nodes 
  for(i=n;i<n+m;i++){
    printf("[%d]= ",i);
    scanf("%d",&p[i]);
  }
  for(i=0;i<n+m;i++){
    printf("[%d]= %d",i,p[i]);
  }
  printf("\n");
  free(p);
  return 0;
}

