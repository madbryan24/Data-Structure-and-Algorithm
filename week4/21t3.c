#include <string.h>
#include <stdio.h>

int main()
{
   char str[80] = "Hoc C -co ban va nang cao -tai VietJack";
   const char s[2] = "-";
   char *token;

   /* lay token dau tien */
   token = strtok(str, s);

   /* duyet qua cac token con lai */
   while( token != NULL ){
      printf( " %s\n", token );
      token = strtok(NULL, s);
   }

   return(0);
}
