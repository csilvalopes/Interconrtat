#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;


int main (void)
{
    fstream flux;
    string myline;
    double total = 0;
    double inter = 0;

    flux.open("line_exo_13.txt");
    cout << setprecision(13);

    if(flux.is_open())
    {
        while (!flux.eof())        
            {
                getline(flux, myline);
                inter = stod(myline, nullptr);
                total += inter;
            }
    }
    else cout << "Impossible d'ouvrir le flux" << endl;

    flux.close();

    myline = to_string(total);
    myline.resize(10);
    cout << myline << endl;
    return 0;
}