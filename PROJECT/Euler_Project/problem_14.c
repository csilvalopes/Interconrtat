// Problem 13


#include <stdio.h>

int main (void)
{

  long long unsigned number = 0, object, chain = 1, max = 0, start;

  for ( number = 2; number < 1e6; number++)
  {
    object = number;
    //printf("Number vaut : %llu\n", number);
    while (object != 1)
    {
      if (object % 2) object = 3 * object + 1;
      else object = object / 2;
      chain++;
      //printf("object vaut : %llu après l'opération : %llu\n", object, chain);
    }
    if (chain > max) 
    {
      max = chain;
      start = number;
    }
    chain = 1;
    if (number % 1000 == 0) printf("Number vaut : %llu et la chaîne max actuelle vaut : %llu\n", number, max);
  }
  
  printf("Le résultat est : %llu\n", start);

  return 0;
}


//////////////////////