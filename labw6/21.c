#include <stdio.h>

enum {SUCCESS, FAIL, MAX_ELEM = 20};

void clear()
{
	int ch;
	while ((ch=getchar()) != '\n' && ch != EOF);
}

typedef struct phoneaddress_t
{
	char name[20];
	char tel[11];
	char email[25];
} phoneaddress;

int main()
{
	FILE *f;
	char filename[] = "phoneadd.txt";
	int reval = SUCCESS;
	phoneaddress phone[MAX_ELEM];
	int n, irc;
	printf("How many contacts do you want to enter?\n");
	scanf("%d", &n);

	clear();
	int i;
	for ( i=0; i<n; i++)
	{
	printf("\nContact %d:\n", i+1);
	printf("- Name: "); gets(phone[i].name);
	printf("- Tel number: "); gets(phone[i].tel);
	printf("- E-mail: "); gets(phone[i].email);
	}
	if ((f = fopen(filename, "wb")) == NULL)
	{
		printf("Cannot open %s.\n", filename);
		reval = FAIL;
	}
	else
	{
		irc = fwrite(phone, sizeof(phoneaddress), n, f);
		printf("fwrite return code = %d\n", irc);
		fclose(f);
	}

	if ((f = fopen(filename, "rb")) == NULL)
	{
		printf("Cannot open %s.\n", filename);
		reval = FAIL;
	}
	else
	{
		irc = fread(phone, sizeof(phoneaddress), n, f);
		printf("fread return code = %d\n", irc);
		int i;
		for (i=0; i<n; i++)
		{
			printf("%s- ", phone[i].name);
			printf("%s- ", phone[i].tel);
			printf("%s\n", phone[i].email);
		}
		fclose(f);
	}
	return reval;
}
