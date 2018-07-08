#include <stdio.h>
#include <stdlib.h>

int main()
{
  float a[50], sum=0, ave, med;
  int n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  for (i=0; i<n; i++)
    {
      printf("a[%d] = ", i+1);
      scanf("%f", &a[i]);
    }
  for (i=0; i<n; i++) sum+=a[i];
  ave = sum/n;
  med = a[0];
  for (i=0; i<n; i++)
    {
      if (abs(a[i]-ave) < abs(med-ave)) med = a[i];
    }
  printf("The median element of the array is %g\n", med);
  return 0;
}
