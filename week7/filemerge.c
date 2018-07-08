#include <stdio.h>
#include <stdlib.h>

typedef struct phone
{
        char model[20];
        int mem;
        float size;
        long int price;
} phone_t;

int linesCounter(FILE *f)
{
  int lines=0;
  while (!feof(f))
  {
          phone_t* tmp = (phone_t*) malloc(sizeof(phone_t));
          lines += fread(tmp, sizeof(phone_t), 1, f);
          free(tmp);
  }
  return lines;
}

int main(int argc, char* argv[])
{
        if (argc != 4)
        {
                printf("\nWrong syntax!\n");
                printf("Should be: filesmerge phone1.dat phone2.dat phone.dat\n\n");
        }
        else
        {
                FILE* f1;
                FILE* f2;
                FILE* f;
                f1 = fopen(argv[1], "rb");
                if (f1 == NULL) printf("Cannot open file %s\n", argv[1]);

                f2 = fopen(argv[2], "rb");
                if (f2 == NULL) printf("Cannot open file %s\n", argv[2]);

                f = fopen(argv[3], "w+b");
                if (f == NULL) printf("Cannot open file %s\n", argv[3]);

                int lines1, lines2;

                lines1 = linesCounter(f1);
                rewind(f1);

                phone_t* phone1 = (phone_t*) malloc(lines1*sizeof(phone_t));
                fread(phone1, sizeof(phone_t), lines1, f1);
                fwrite(phone1, sizeof(phone_t), lines1, f);
                free(phone1);

                lines2 = linesCounter(f2);
                rewind(f2);

                phone_t* phone2 = (phone_t*) malloc(lines2*sizeof(phone_t));
                fread(phone2, sizeof(phone_t), lines2, f2);
                fwrite(phone2, sizeof(phone_t), lines2, f);
                free(phone2);

                printf("\n- %s: %d\n", argv[1], lines1);
                printf("- %s: %d\n", argv[2], lines2);
                printf("\nAfter merge:\n");
                printf("- %s: %d\n", argv[3], lines1+lines2);

                fclose(f1);
                fclose(f2);
                fclose(f);
        }
        return 0;
}
