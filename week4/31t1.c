#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct point{
  double x;
  double y;
}point_t;

typedef struct circle{
  point_t center;
  double R;
}circle_t;

int main(){
    int i,n;
    circle_t *p=NULL;
    do{
        printf("How many circle do you want to create(0<n<=10): ");
        scanf("%d",&n);
    }while(n<=0 || n>10);

    p=(circle_t *)malloc(n*sizeof(circle_t));
    if(p==NULL){
        printf("failed to provide memories");
        exit(0);
    }
    else{
        printf("providing memories successfully\n");
            for(i=0;i<n;i++){
                printf("the coordinates of circle %d: ",i);
                scanf("%lf %lf",&((p+i)->center.x),&((p+i)->center.y));
                printf("The radius of the circle: %d: ",i);
                scanf("%lf",&((p+i)->R));
            }
        for(i=0;i<n;i++){
            printf("O%d = (%lf,%lf)\n",i,(p+i)->center.x,(p+i)->center.y);
            printf("R%d = %lf\n",i,(p+i)->R);
        }
    }
    return 0;
}
