// Problem 2

#include <stdio.h>

int main (void)
{

  long long unsigned Nombre = 600851475143, count = 1, prime[1000000];
  int test = 1, j;

  prime[0] = 2;

  for (int i = 3; i < Nombre; i++)
  {
    for (j = 0; j < count; j++)
    {
      
      if (test && !(i % prime[j]))
      {
        test = 0;
        j = count;
      }

    }

    if (test)
    {
      prime[count] = i;
      count++;
    }

      test = 1;

    if (count == 10001) break;

  }

  printf("Le résultat est : %llu\n", prime[count-1]);

  return 0;

}


//////////////////////