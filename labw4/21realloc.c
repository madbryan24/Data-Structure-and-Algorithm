#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
  char *str;
  str=(char *)malloc(15);
  strcpy(str,"tutorialspoint");
  printf("string: %s, address: %p \n",str,str);
  // initial memory allocation
  str=(char *)realloc(str,25);
  strcat(str,".com");
  printf("String: %s, Address: %p \n",str,str);
  free(str);
  return 0;
}
