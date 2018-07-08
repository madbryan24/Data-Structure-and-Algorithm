#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
typedef struct point{
  double x;
  double y;
}point_t;

typedef struct circle{
  point_t center;
  double R;
}circle_t;

float Random(float a, float b)
{
    return a + (b - a)*rand()/RAND_MAX;
}

int main(){
    int i,j,n,choice,max,imax;
    circle_t *p=NULL;
    int count[MAX][MAX]={0};
    int fi[MAX]={0};
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
        do{
            printf("Do you want to create circles manually(1) or automatically(2): ");
            scanf("%d",&choice);
        }while(choice!=1 && choice!=2);

        if(choice==1){
            for(i=0;i<n;i++){
                printf("the coordinates of circle %d: ",i);
                scanf("%lf %lf",&((p+i)->center.x),&((p+i)->center.y));
                printf("The radius of the circle: %d: ",i);
                scanf("%lf",&((p+i)->R));
            }
            for(i=0;i<n;i++){
                printf("O[%d]= %f %f\n",i,(p+i)->center.x,(p+i)->center.y);
                printf("R[%d]= %f\n",i,(p+i)->R);
            }
        }
        else if(choice==2){
            srand(time(NULL));
            for(i=0;i<n;i++){
                (p+i)->center.x=Random(-50.0,50.0);
                (p+i)->center.y=Random(-50.0,50.0);
                (p+i)->R=Random(0.0,50.0);
                printf("O[%d]= %f %f\n",i,(p+i)->center.x,(p+i)->center.y);
                printf("R[%d]= %f\n",i,(p+i)->R);
            }
        }
//choose to create circle
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                float d= (((p+i)->center.x)-((p+j)->center.x))*(((p+i)->center.x)-((p+j)->center.x))+(((p+i)->center.y)-((p+j)->center.y))*(((p+i)->center.y)-((p+j)->center.y));
                if(d>=(((p+i)->R)-((p+j)->R))*(((p+i)->R)-((p+j)->R)) && d<=(((p+i)->R)+((p+j)->R))*(((p+i)->R)+((p+j)->R))){
                    count[i][j]++;
                    count[j][i]++;
                    fi[i]++;
                    fi[j]++;
                }
            }
        }
//check if the circles intersect the others
        imax=0;
        max=fi[0];
        for(i=1;i<n;i++){
            if(fi[i]>max){
               max=fi[i];
               imax=i;
            }
        }
        printf("the circle intersecting the others the most is circle[%d]= %d\n",imax,fi[imax]);
        for(j=0;j<n;j++){
            if(count[imax][j]>0) printf("with circle[%d]\n",j);
        }
    }
    return 0;
}
