#include<stdio.h>
#include<string.h>
void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}
void sort(char name[50][25],int n){
    char string[50][10],tmp[25],tmp1[25],tmp2[25];
    int max[n];
    int i,k,j,count=1,x;
    for(i=0;i<n;i++){
        strcpy(string[i],"");
        j=0;
        k=strlen(name[i])-1;
        while(name[i][k]!=' '){
            string[i][j]=name[i][k];
            k--;
            j++;
        }
        string[i][j]='\0';
        strrev(string[i]);;
        printf("%d. %s\n",i+1,string[i]);
    }
    for(i=0;i<n-1;i++){
        for(k=i+1;k<n;k++){
            if(strcmp(string[i],string[k])>0){
            strcpy(tmp1,name[i]);
            strcpy(tmp2,name[k]);
            strcpy(tmp,tmp1);
            strcpy(tmp1,tmp2);
            strcpy(tmp2,tmp);
            strcpy(name[i],tmp1);
            strcpy(name[k],tmp2);
            }
            else if(strcmp(string[i],string[k])==0){
                count++;
                }
        }
        max[i]=count;
        count=1;
    }
    int maximum=max[0];
	for(i=0;i<n-1;i++){
		if(max[i]>maximum) maximum=max[i];
	}
    printf("The maximum number of students who have the same name: %d\n",maximum);
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
    sort(name,n);
    for(i=0;i<n;i++){
        printf("%d. %s\n",i+1,name[i]);
    }
    return 0;
}
