#include<stdio.h>
#define AL_LEN 26
int main(){
  int i=0;
  int count[AL_LEN]={0};
  char c='\0';
  printf("enter a line of text: \n");
  c=getchar();
  while(c!='\n' && c>=0){
    if(c<='z' && c>='a')
      ++count[c-'a'];
    if(c<='Z' && c>='A')
      ++count[c-'A'];
    c=getchar();
  }
  for(i=0;i<AL_LEN;++i){
    if(count[i]>0)
      printf("the character %c apprears %d times \n ",'a'+i,count[i]);
  }
  
  return 0;
}
