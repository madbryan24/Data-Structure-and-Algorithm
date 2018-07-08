#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void BlockReadWrite(FILE *fin,FILE *fout){
	int num;
	char buff[MAX+1];

	while(!feof(fin)){
		num=fread(buff,sizeof(char),MAX,fin);
		buff[num*sizeof(char)]='\0';
        printf("%d\n",num);
		printf("%s",buff);
		fwrite(buff,sizeof(char),num,fout);
	}
}
int main(){
	FILE *fin,*fout;
	if((fin=fopen("file11.txt","r+"))==NULL){
		printf("cannot open file1!\n");
		exit(1);
	}
	else if((fout=fopen("file12.txt","w+"))==NULL){
		printf("cannot open file2!\n");
		exit(1);
	}
	else{
	   	BlockReadWrite(fin,fout);
		fclose(fin);
		fclose(fout);
	}

	return 0;
}
