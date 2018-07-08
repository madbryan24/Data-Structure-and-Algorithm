#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 80
enum {SUCCESS, FAIL};

void clear_buffer(){
    int ch;
    while((ch=getchar())!='\n' && ch!=EOF);
}

typedef struct address{
	char name[20];
	char tel[11];
	char email[25];
}address_t;

int main(){
    address_t list[100];
	FILE *fp;
	char filename2[] = "file21.txt";
	int reval = SUCCESS;
	int i,irc,n=0;
		printf("how many phoenaddress you want to add: ");
		scanf("%d",&n);
		clear_buffer();
		for (i=0;i<n;i++){
			printf("name[%d]= ",i);
			fgets(list[i].name,20,stdin);

			printf("tel[%d]= ",i);
			fgets(list[i].tel,11,stdin);

			printf("email[%d]= ",i);
		   	fgets(list[i].email,25,stdin);

		}
    if ((fp = fopen(filename2, "wb")) == NULL){
		printf("Cannot open %s.\n", filename2);
		reval = FAIL;
	}
	else{
			irc=fwrite(list,sizeof(address_t),n,fp);
			printf("code: %d\n",irc);
			fclose(fp);
	}
	if ((fp = fopen(filename2, "rb")) == NULL)
	{
		printf("Cannot open %s.\n", filename2);
		reval = FAIL;
	}
	else{
        printf("n=%d\n",n);
		irc= fread(list,sizeof(address_t),n,fp);
		printf("return code: %d \n",irc);
        for(i=0;i<n;i++){
                printf("Contact[%d]: \n",i);
				printf("    name[%d]= %s",i,list[i].name);
				printf("    tel[%d]= %s",i,list[i].tel);
				printf("    email[%d]= %s",i,list[i].email);
	  	}
	   	fclose(fp);
	}
	return 0;
}
