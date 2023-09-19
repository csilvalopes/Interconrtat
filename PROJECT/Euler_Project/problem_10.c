// Problem 18


#include <stdio.h>

int main (void)
{

  long long unsigned prime[1000000];
  prime[0] = 2;
  long count = 1;
  long long unsigned number = 3, i, result = 0;
  char test = 1;

  while (prime[count -1] < 2e6)
  {
    for ( i = 0; i < count; i++)
    {
      if (test && !(number % prime[i]))
      {
        test = 0;
        i = count;
      }
    }

    if (test)
    {
      prime[count] = number;
      count++;
    }
    

    test = 1;
    number++;
    if ( number % 100000 == 0) printf("%llu\n", number);
  }
  
  for (i = 0; i < count-1; i++)
  {
    result += prime[i];
  }
  
  
  printf("Le résultat est : %llu\n", result);
}


//////////////////////