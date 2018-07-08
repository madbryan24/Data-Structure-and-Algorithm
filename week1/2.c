#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
  int i;
  char sen[40];
  char article[5][5] = {"the", "a", "one", "some", "any"};
  char noun[5][5] = {"boy", "girl", "dog", "town", "car"};
  char verb[5][8] = {"drove", "jumped", "ran", "walked", "skipped"};
  char prep[5][6] = {"to", "from", "over", "under", "on"};
  srand(time(NULL));
  printf("Generate 10 sentences:\n");
  //article - noun - verb - preposition - article - noun
  for (i=0; i<10; i++)
    {
      strcpy(sen, "");
      strcat(sen, article[rand()%5]);
      strcat(sen, " ");
      strcat(sen, noun[rand()%5]);
      strcat(sen, " ");
      strcat(sen, verb[rand()%5]);
      strcat(sen, " ");
      strcat(sen, prep[rand()%5]);
      strcat(sen, " ");
      strcat(sen, article[rand()%5]);
      strcat(sen, " ");
      strcat(sen, noun[rand()%5]);
      strcat(sen, ".");
      sen[0] = sen[0] - 32;
      printf("%d. %s\n", i+1, sen);
    }
  return 0;
}
