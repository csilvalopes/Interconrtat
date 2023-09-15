#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <vector>
#include<algorithm>

using namespace std;

char Alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y', 'Z'};

int main (void)
{
    fstream flux;
    string myline;
    string inter;
    long long total = 0, total_nom = 0;
    int i = 0, j = 0, index = 0;
    vector<string> noms_triees;


    cout << setprecision(15);

    flux.open("0022_names.txt");

    if(flux.is_open())
    {
        while (!flux.eof())        
            {
                getline(flux, myline, ',');
                inter = myline.substr(1,myline.size()-2);
                noms_triees.push_back(inter);

            }
            sort(noms_triees.begin(), noms_triees.end());
            
    }
    else cout << "Impossible d'ouvrir le flux" << endl;

    while (index < noms_triees.size())
    {
                cout << noms_triees[index] << endl;
                total_nom = 0;
                for (i = 0; i < noms_triees[index].size(); i++)
                {
                    j = 0;
                    while (noms_triees[index][i] != Alphabet[j]) j++;
                    total_nom += j;
                }
                total_nom += noms_triees[index].size();
                total += (total_nom * (index+1));
                cout << "Le total à l'index " << index << " vaut " << total << endl;
                index++;
    }
    

    cout << "Le total final est : "  << total << endl;
    flux.close();
    return 0;
}


                // for (i = 0; i < inter.size(); i++)
                // {
                //     j = 0;
                //     while (inter[i] != Alphabet[j]) j++;
                //     total_nom += j;
                // }
                // total_nom += inter.size();
                // total += (total_nom * index);
                // cout << "Le total à l'index " << index << " vaut " << total << endl;
                // index++;