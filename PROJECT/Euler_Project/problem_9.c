// Problem 9

#include <stdio.h>
#include <math.h>

int main (void)
{

  int a, b, c_pow;
  double c;

  for (a = 999; a > 1; a--)
  {
    for (b = 999; b > 1; b--)
    {
      if ( (a + b) < 1000)
      {
        c_pow = a * a + b * b;
        c = sqrt(c_pow);
        if ( (c == (int) c) && ( (a + b + c) == 1000))
        {
          printf("Le résultat est : %f; avec a = %d, b = %d, et c = %f\n", a*b*c, a , b, c);
          goto la;
        }
      }
    }
    
  }
  
  la : return 0;
}


//////////////////////