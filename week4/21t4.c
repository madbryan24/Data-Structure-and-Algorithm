#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("the number of arguments should be 3!");
        return 0;
    }

    int number = 5;
    char word[5][MAX] = {"dare","bitch","bastard","shit","damn"};
    char s[MAX] = "";
    char content[MAX] = "";

    char filename[MAX] = "";
    strcat(filename, argv[1]);

    char  sym = atoi(argv[2]);
    printf("sym is %d\n",sym);

    //filename = "file1.txt";
    FILE *fp = fopen(filename,"r+");
    if(fp==NULL)
    {
        printf("cannot open file1!");
        return 0;
    }

    printf("open file successfully!\n\n");

    char c;
    int i = 0;
    int k = 0;
    int len = 0;
    while(1)
    {
        c = fgetc(fp);

        content[k] = c;
        k += 1;

        if(c != ' ' && c != '\n' && c != EOF)
        {
            s[i] = c;
            i++;
        }
        else
        {
            len = i;
            s[i]='\0';
            for(i = 0; i < number; i++)
            {
                if( strcmp (s, word[i]) == 0 )
                {
                    for(i = 0; i < len; i++) s[i] = sym;
                    break;
                }
            }

            i = 0;
            printf("%s",s);
            putchar(' ');
        }

        if(c == EOF) break;
    }
    fclose(fp);

    k -= 1;
    content[k] = '\0';
    printf("\nFile Content: [%s]", content);

    return 0;
}
