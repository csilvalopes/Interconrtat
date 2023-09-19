// Problem 16

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main(void)
{

  long double number = 1, count = 0;

  for (int i = 1; i <= 100; i++)
  {
    number *= i;
  }

  string str_number = to_string(number);
  cout << str_number << endl;
  int size = str_number.size();

  cout << "La taille est : " << size << endl;

  for (int i = 0; i < size; i++)
  {
    if ((str_number[i] - '0') > 0 &&  (str_number[i] - '0') < 10)
      count += str_number[i] - '0';
  }

  cout << "Le nombre vaut : " << number << " et la somme de tous ses chiffres vaut : " << count << endl;
}

//////////////////////