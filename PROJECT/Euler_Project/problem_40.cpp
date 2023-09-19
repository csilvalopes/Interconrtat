// Problem 40

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main (void)
{

  string _tab;
  int k = 1;

  do
  {
    _tab += to_string(k);
    k++;
  } while (_tab.size() < 1e6);


  cout << "La 1 ère valeur est " << _tab[0] << endl;
  cout << "La 10 ème valeur est " << _tab[9] << endl;
  cout << "La 100 ème valeur est " << _tab[99] << endl;
  cout << "La 1 000 ème valeur est " << _tab[999] << endl;
  cout << "La 10 000 ème valeur est " << _tab[9999] << endl;
  cout << "La 100 000 ème valeur est " << _tab[99999] << endl;
  cout << "La 1 000 000 ème valeur est " << _tab[999999] << endl;


  long long unsigned result = (_tab[0] - '0') * (_tab[9] - '0') * (_tab[99] - '0') * (_tab[999] - '0') * (_tab[9999] - '0') * (_tab[99999] - '0') * (_tab[999999] - '0');

  cout << "Le résultat est : " << result << endl;

}


//////////////////////