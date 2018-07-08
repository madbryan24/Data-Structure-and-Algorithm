#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc,char* argv[]){
  while(argc!=4){
    printf("argc should be 4 !");
    return 1;
  }
  float x,x1,x2;
  int a=atof(argv[1]);
  int b=atof(argv[2]);
  int c=atof(argv[3]);
  if(a==0 && b!=0){
    x=(float)-c/b;
    printf("the solution of the equation is: %f\n",x);
  }
  else if(a==0 && b==0){
    if(c==0) printf("the equation has infinite solutions\n");
    else if(c!=0) printf("the equation has no solution\n");
  }
  else if(a==0 && b==0 && c==0){
    printf("the equation has infinite solutions\n");
  }
  else if((b==0 && c==0)||(a==0 && c==0)){
    x=0;
    printf("the equation has unique solution: %f\n",x);
  }
  else if(b==0 && a!=0 && c!=0){
    if(c/a>0) printf("the equation has no solution\n");
    else if(c/a<0){
      x1=(float)sqrt(-c/a);
      x2=-(float)sqrt(-c/a);
    }
  }
  else if(a!=0 && b!=0 && c==0){
    x1=0.0;
    x2=-b/a;
    printf("x1=%.2f  x2=%.2f\n", x1, x2);
  }
  else if(a!=0 && b!=0 && c!=0){
    float delta=b*b-4*a*c;
    if( delta < 0) printf("The equation has no solution \n");
    else{
      x1=(-b-sqrt(delta))/(2*a);
      x2=(-b+sqrt(delta))/(2*a);
      printf("x1=%.2f  x2=%.2f\n", x1, x2);
    }
  }
    
  return 0;
}
