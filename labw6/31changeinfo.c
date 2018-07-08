#include<stdio.h>
#include<stdlib.h>

enum {SUCCESS, FAIL, MAX_ELEM = 20};

typedef struct phoneaddress_t
{
	char name[20];
	char tel[11];
	char email[25];
} phoneaddress;

int main(){
	FILE *fp;
	phoneaddress *pa;
	int i,n,irc,irc1;
	int reval=SUCCESS;
	printf("read from 2nd to 3rd \n");

	if ((fp = fopen("file21.txt", "r+b")) == NULL)
	{
		printf("Cannot open phoneadd.txt.\n");
		return FAIL;
	}

	pa=(phoneaddress*)malloc(2*sizeof(phoneaddress));
	if(pa==NULL){
		printf("memory allocation failed");
		reval=FAIL;
	}

	irc=fread(pa,sizeof(phoneaddress),1,fp);
	printf("return code1: %d \n",irc);
	if(fseek(fp,2*sizeof(phoneaddress),SEEK_SET)!=0){
		printf("fseek failed");
		return FAIL;
	}
	irc1=fread(pa+1,sizeof(phoneaddress),1,fp);
	printf("return code2: %d \n",irc1);

        for(i=0;i<2;i++){
                printf("Contact[%d]: \n",i);
				printf("    name[%d]= %s",i,pa[i].name);
				printf("    tel[%d]= %s",i,pa[i].tel);
				printf("    email[%d]= %s",i,pa[i].email);
	  	}

    phoneaddress tmp;
    tmp=pa[0];
    pa[0]=pa[1];
    pa[1]=tmp;

    printf("info after changing: \n");
    for(i=0;i<2;i++){
                printf("Contact[%d]: \n",i);
				printf("    name[%d]= %s",i,pa[i].name);
				printf("    tel[%d]= %s",i,pa[i].tel);
				printf("    email[%d]= %s",i,pa[i].email);
	  	}
	fclose(fp);
	free(pa);
	return reval;
}
