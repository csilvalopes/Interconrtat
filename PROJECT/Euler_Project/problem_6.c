// Problem 6

#include <stdio.h>

int main (void)
{
  long long sum1 = 0, sum2 = 0, sum2_pow = 0, result = 0;

  for (int i = 1; i <= 100; i++)
  {
    sum1 += i * i;
    sum2 += i;
  }
  
  sum2_pow = sum2 * sum2;

  result = sum2_pow - sum1;

  printf("%llu\n", result);

  return 0;
}


//////////////////////