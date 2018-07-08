#include <stdio.h>
#include <string.h>
enum {SUCCESS, FAIL};
void clear_buffer() {
  int ch;
  while ((ch=getchar()) !='\n' && ch!=EOF);
}
void Readfull(FILE *fin)
{
  int ch;
  while ((ch=fgetc(fin)) != EOF)
    {
      putchar(ch);
    }
}
void Readpage(FILE *fin)
{
  int curr_lines = 0, ch;
  while ((ch = fgetc(fin)) != EOF)
    {
      putchar(ch);
      if (ch == '\n'){
	  curr_lines++;
        if (curr_lines == 25){
	      printf("\n");
	      curr_lines = 0;
	      clear_buffer;
	      printf("Press enter to move to the next page: ");
	      getchar();
	      printf("\n");
        }
        }
    }
}
int main(int argc, char* argv[]){
  FILE *fptr1;
  if ((argc == 3) && (strcmp(argv[2],"-p") == 0))
    {
        if ((fptr1 = fopen(argv[1], "r")) == NULL)
	{
        printf("Cannot open %s.\n", argv[1]);
        return 1;
	}
        Readpage(fptr1);
        fclose(fptr1);
    }
    else if ((argc == 3) && (strcmp(argv[2],"-p") != 0)){
        printf("Wrong syntax!\n");
        return 1;
    }
    else if ((argc > 3) || (argc == 1)){
        printf("Wrong number of argument!\n");
        return 1;
    }
    else if (argc == 2){
        if ((fptr1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        return 1;
        }
        Readfull(fptr1);
        fclose(fptr1);
    }
  return 0;
}
