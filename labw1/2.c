#include <stdio.h>

int compare (int a[50], int b[50], int n)
{
  int i, count1=0, count2=0;
  for (i=0; i<n; i++)
    {
      if (a[i] == b[i]) count1++;
    }
  for (i=0; i<n; i++)
    {
      if (a[i] == b[n-i-1]) count2++;
    }
  if (count1 == n) return 1;
  else if (count2 == n) return -1;
  else return 0;
}

int main()
{
  int a[50], b[50], n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Array 1:\n");
  for (i=0; i<n; i++)
    {
      printf("a[%d] = ", i+1);
      scanf("%d", &a[i]);
    }
  printf("Array 2:\n");
  for (i=0; i<n; i++)
    {
      printf("b[%d] = ", i+1);
      scanf("%d", &b[i]);
    }
  if (compare(a,b,n) == 1) printf("They are equal\n");
  else if (compare(a,b,n) == -1) printf("They are symetric\n");
  else printf("They are different\n");
  return 0;
}
