// Problem 4

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main (void)
{

  long long unsigned result, max = 0;
  string str_result;

  for (int i = 999; i > 100; i--)
  {
    for (int j = 999; j > 100; j--)
    {
      result = i * j;
      str_result = to_string(result);

      switch (str_result.length())
      {
      case 5 :
        if ( (str_result[0] == str_result[4]) && (str_result[1] == str_result[3]) ) if (result > max) max = result;
        break;
      case 6 :
        if ( (str_result[0] == str_result[5]) && (str_result[1] == str_result[4]) && (str_result[2] == str_result[3]) ) if (result > max) max = result;
        break;
      default:
        break;
      }
    }
    
  }
  
  cout << max << endl;

}

//////////////////////