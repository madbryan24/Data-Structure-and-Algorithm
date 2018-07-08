#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
void clear_buffer(){
  int ch;
  while((ch=getchar()) != '\n' && (ch=getchar()) !=EOF );

}
int main(){
  char s1[MAX]="";
  char s2[MAX]="";
  int n1,n2,n,i;
  char *p;
  printf("please enter string 1\n");
  fgets(s1,MAX,stdin);
  clear_buffer();
  printf("please enter string 2\n");
  fgets(s2,MAX,stdin);
  n1=strlen(s1);
  n2=strlen(s2);
  n=n1+n2+1;
  p=(char *)malloc(n*sizeof(int));
  printf("\n");
  strcpy(p,s1);
  strcpy(p+n1,s2);
 
  for(i=0;i<n;i++){
    printf("%c",p[i]);
  }
  printf("\n");
  return 0;
}
