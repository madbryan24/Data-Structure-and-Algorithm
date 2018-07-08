#include<stdio.h>
#include<string.h>
int main(){
  int check=0,i;
  char string[100];
  char c;
  printf("please enter a string \n");
  scanf("%s",string);
  for(i=0;i<strlen(string);i++){
    if(string[i]!=' ') putchar(string[i]);
    else if(string[i]=' '){
      if(check=0){
      check=1;
      putchar('\n');
      }
    }  
  }  
  return 0;
}
