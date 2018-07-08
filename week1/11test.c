#include<stdio.h>
#include<string.h>
void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

int main(){
    int n,i;
    char name[50][25];
    // khai bao so hoc sinh
    do{
        printf("please enter the number of students(1<=n<=50): ");
        scanf("%d",&n);
    }while(n<1 || n>50);
    clear_buffer();
    // khai bao ten
    for(i=0;i<n;i++){
        printf("name of student %d: ",i+1);
        gets(name[i]);
    }
    // sap xep ten
    for(i=0;i<n;i++){
        printf("%d. %s\n",i+1,name[i]);
    }
    return 0;
}
    for(i=0;i<n-1;i++){
        for(k=i+1;k<n;k++){
            if(strcmp(string[i],string[k])>0){
            strcpy(tmp,string[i]);
            strcpy(string[i],string[k]);
            strcpy(string[i],tmp);
            }
        }
    }
