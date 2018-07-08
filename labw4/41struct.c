#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct point{
  double x;
  double y;
}point;

typedef struct circle{
  point center;
  double R;
}circle;

int main(){
  point A;
  circle O;
  double d;
  printf("the coordinates of A:");
  scanf("%lf %lf",&(A.x),&(A.y));
  printf("the coordinates of O:");
  scanf("%lf %lf",&(O.center.x),&(O.center.y));
  printf("The radius of the circle: ");
  scanf("%lf",&(O.R));
  d=sqrt((A.x-O.center.x)*(A.x-O.center.x) + (A.y-O.center.y)*(A.y-O.center.y));
  if(d==O.R) printf("A is on the circle \n");
  else if(d>O.R) printf("A is outside of the circle \n");
  else if(d<O.R) printf("A is inside of the circle \n");
  return 0;
}
