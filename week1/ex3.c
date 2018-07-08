#include <stdio.h>
#define MAX1 30
#define MAX2 50
#include <string.h>
typedef struct{
	char name[MAX2];
	char first[MAX2];
}student;
void print(student a[],int n){
	int i;

	for(i=0;i<n;i++){
		printf("%d: %s\n",i+1,a[i].name);
	}
}
void replace(char full[],char first[]){
	int i;
	int n=strlen(full);
	int m=0;
	for(i=n-1;full[i]!=' ';i--){
		first[m]=full[i];
		m++;
	}
	first[m]=0;
    strrev(first);
}
void sortName(student a[],int n){
	int i,j,t,k,count=1;
	int max[n];
	student tmp;
	for(i=0;i<n;i++){
		replace(a[i].name,a[i].first);
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			t=strcmp(a[i].first,a[j].first);
			if(t>0){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
			else if(t==0){
				count++;
				k=strcmp(a[i].name,a[j].name);
				if(k>0){
					tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;
				}
			}
		}
		max[i]=count;
		count=1;
	}
	int maximum=max[0];
	for(i=0;i<n-1;i++){
		if(max[i]>maximum) maximum=max[i];
	}
	print(a,n);
	printf("The maximum number of students who have the same name: %d\n",maximum);
}

int main(){
	int n;
	printf("Enter the number of students: ");
	scanf("%d%*c",&n);
	int i;
	student STU[MAX1];
	printf("Enter student's name: \n");
	for(i=0;i<n;i++){
		printf("%d: ",i+1);
		gets(STU[i].name);
	}
	printf("\n");
	printf("Student list: \n");
	sortName(STU,n);

	return 0;
}


