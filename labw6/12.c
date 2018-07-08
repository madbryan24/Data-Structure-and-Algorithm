#include <stdio.h>
#include<stdlib.h>
#define MAX_LEN 80

enum {SUCCESS, FAIL};

void BlockReadWrite(FILE *fin, FILE *fout)
{
	int num;
	char buff[MAX_LEN+1];
	while (!feof(fin))
	{
	num = fread(buff, sizeof(char), MAX_LEN, fin);
	buff[num*sizeof(char)] = '\0';
	printf("%s", buff);
	fwrite(buff, sizeof(char), num, fout);
	}
}

int main()
{
	FILE *f1;
	FILE *f2;
	char filename1[] = "file11.txt";
	char filename2[] = "file12.txt";
	int reval = SUCCESS;
	if ((f2 = fopen(filename2, "w")) == NULL)
	{
		printf("Cannot open %s.\n", filename2);
		reval = FAIL;
	}
	else if ((f1 = fopen(filename1, "r")) == NULL)
	{
		printf("Cannot open %s.\n", filename1);
		reval = FAIL;
	}
	else
	{
		BlockReadWrite(f1,f2);
		fclose(f1);
		fclose(f2);
	}
	return reval;
}
