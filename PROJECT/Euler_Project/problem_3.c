// Problem 2

#include <stdio.h>

int main (void)
{


  long long unsigned Nombre = 600851475143, count = 1, prime[200000];
  int test = 1, j, result;

  prime[0] = 2;

  for (int i = 3; i < 775146; i++)
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

  }

  for (int i = 0; i < count; i++)
  {
    if ((Nombre % prime[i]) == 0 ) result = prime[i];
  }
  
  printf("Le résultat est : %d\nCount est monté jusqu'à : %lld\n", result, count);

  return 0;

}


//////////////////////