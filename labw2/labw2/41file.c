#include<stdio.h>
enum{SUCCESS,FAIL};
int main(){
  FILE *fp;
  char filename[]="file.txt";
  int reveal= SUCCESS;

  if((fp=fopen("/home/students/20163922/DSaA/file.txt","r"))==NULL){
    printf("Cannot open %s\n",filename);
    reveal=FAIL;
  }
  else{
    printf("the value of fp: %p\n",fp);
    printf("Ready to close the file \n");
    fclose(fp);
  }
  return reveal;
}
