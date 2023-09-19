// Problem 1

#include <stdio.h>

int main (void)
{
  int n = 1000;

  int sum = 0;

  for(int i; i < n; i++)
  {
    if ( (i % 3) == 0)
    {
      sum  += i;
    }
    else if ( (i % 5) == 0)
    {
      sum += i;
    }
  }

  printf("Le résultat est %d pour n = %d\n", sum, n);
  return 0;
}


//////////////////////