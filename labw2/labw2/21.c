#include<stdio.h>
#include<string.h>
void replace_char(char *str,char c1,char c2){
  int i;
  for(i=0;i<strlen(str);i++){
    if(*(str+i)=c1) *(str+i)=c2;
  }
}
int main(){
  char *str="";
  char c1,c2;
  replace_char("papa",'p','h');
  printf("The new array is: %s\n",str);
  return 0;
}
