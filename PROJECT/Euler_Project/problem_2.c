// Problem 2

#include <stdio.h>

int main (void)
{
  int count = 0, start = 1;
  long long pre_previous = 1, previous_fibbo = 1, fibbo = 1;

  do
  {
    fibbo = pre_previous + previous_fibbo;
    pre_previous = previous_fibbo;
    previous_fibbo = fibbo;

    if ( (fibbo % 2) == 0) count += fibbo;
    


  } while (fibbo < 4e6);
  
  printf("Le nombre de valeur paire est %d\n", count);

  return 0;
}


//////////////////////