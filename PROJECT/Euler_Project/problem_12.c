// Problem 12


#include <stdio.h>

int main (void)
{

  int divider = 1, max = 1;
  long long unsigned triangle_number = 0, i, j, count = 1;

  while (1)
  {

    triangle_number += count;

    for ( j = 2; j <= triangle_number; j++)
    {
      if (triangle_number % j == 0) divider++;
    }
    if (divider > max) max = divider;
    if (count % 100 == 0)
    {
      printf("count = %llu\n", count);
      printf("max divider = %d\n", max);
    }
    if (divider >= 500) goto la;
    count++;
    divider = 1;
  }
  

  la : printf("Le résultat est : %llu\n", triangle_number);
  return 0;
}


//////////////////////