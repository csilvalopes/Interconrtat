// Problem 16

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main (void)
{

double number = pow(2, 1000), count = 0;
string str_number = to_string(number);
int size = str_number.size();

cout << "La taille est : " << size << endl;

for (int i = 0; i <= size; i++)
{
  if ( (str_number[i] - '0') >= 0 ) count += str_number[i] - '0';
}

cout << "2 à la puissance 1000 vaut : " << number << " et la somme de tous ses chiffres vaut : " << count << endl;

}


//////////////////////