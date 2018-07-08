#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct stack_t{
  int stk[MAX];
  int top;
}stack;

stack s1;
stack s2;
stack result;

void init(stack s){
  s.top = 0;
}

int isEmpty(stack s){
  if(s.top == 0) return 1;
  else return 0;
}

int isFull(stack s){
  if(s.top == MAX) return 1;
  else return 0;
}

void push(stack s,int num){
  if(isFull(s)){
    printf("Stack is full\n");
    return;
  }
  else{
    s.stk[s.top] = num;
    printf("%d",s.stk[s.top]);
    s.top++;
  }
}

int pop(stack s){
  int num;
  if(isEmpty(s)){
    printf("Stack is empty\n");
    return;
  }
  else{
    num=s.stk[s.top];
    s.top=s.top-1;
    return num;
  }
}

void display(stack s){
  int i;
  if(isEmpty(s)){
    printf("Stack is empty\n");
    return;
  }
  else{
    printf("the result number : ");
    for(i=s.top;i>=0;i--){
      printf("%d",s.stk[i]);
    }
    printf("\n");
  }
}

int main(){
  char st1[MAX],st2[MAX];
  init(s1);
  init(s2);
  init(result);
  printf("Enter the first number : ");
  gets(st1);
  printf("Enter the second number : ");
  gets(st2);
  int i;
  int m[MAX],h[MAX];

  for(i=0;i<strlen(st1);i++){
    m[i]=(int)st1[i];
    push(s1,m[i]);
  }
  printf("\n");

  for(i=0;i<strlen(st2);i++){
    h[i] =(int)st2[i];
    push(s2,h[i]);
  }
  printf("\n");
  //sum//
  int num=0;
  while(isEmpty(s1)!=1 || isEmpty(s2)!=1){
    num=num+pop(s1)+pop(s2);
    if(num>=10) {
      num=num-10;
      push(result,num);
      num=1;
    }
    else{
      push(result,num);
      num=0;
    }
  }

  display(result);
    


  return 0;

}

    
    
