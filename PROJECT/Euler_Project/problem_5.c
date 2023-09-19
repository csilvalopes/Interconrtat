// Problem 5

#include <stdio.h>

int main (void)
{

  int test = 1, i, j = 20, div = 1;


  while (test)
  {
    j++;
    for (i = 1; i < 20; i++)
    {
      if ( (j % i) ) div = 0;
    }

    if (div) test = 0;
    div = 1;

  }
  
  printf("Le résultat est : %d\n", j);

  return 0;
}


//////////////////////