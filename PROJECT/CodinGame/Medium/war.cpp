#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int Value_Card(const int length, const string card)
{
        if (length>2) return 10;
        else if (isalpha(card[0]))
        {
            switch(card[0])
            {
                case 'A':
                return 14;
                break;
                case 'K':
                return 13;
                break;
                case 'Q':
                return 12;
                break;
                case 'J':
                return 11;
                break;
                default:break;
            }
        }
        else return card[0] - 48;

};

int main()
{

    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    string tas_J1;
    string tas_J2;

    for (int i = 0; i < n; i++) {
        string cardp_1; // the n cards of player 1
        cin >> cardp_1; cin.ignore();
        tas_J1 += cardp_1 + ";";
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp_2; // the m cards of player 2
        cin >> cardp_2; cin.ignore();
        tas_J2 += cardp_2 + ";";
    }


    int turn = 0, bat = 0;
    
    string card_j1;
    string card_j2;
    static string def_j1, def_j2;
    here : int val1 = 0, val2 = 0;

    while ((n > 0) && (m > 0))
    {

        int i1 = 0, i2 = 0;
        string card_j1, card_j2;

        while (tas_J1[i1] != ';') card_j1 += tas_J1[i1++];
        while (tas_J2[i2] != ';') card_j2 += tas_J2[i2++];

        def_j1 +=  card_j1 + ";";
        def_j2 += card_j2 + ";";

        val1 = Value_Card(i1, card_j1);
        val2 = Value_Card(i2, card_j2);

        if (val1 > val2)
        {
            if (bat)
            {
                tas_J1 +=  def_j1 + def_j2;
                n += bat * 8;
            }
            else tas_J1 +=  card_j1 + ";" + card_j2+ ";";
            tas_J1.erase(0,i1+1);
            tas_J2.erase(0,i2+1);
            n++;
            m--;

        }
        else if (val2 > val1)
        {
            if (bat) 
            {
                tas_J2 +=  def_j1 + def_j2;
                m += bat * 8;
            }
            else tas_J2 +=  card_j1 + ";" + card_j2+ ";";
            tas_J1.erase(0,i1+1);
            tas_J2.erase(0,i2+1);
            m++;
            n--;
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                int indice = i1+1;
                while(tas_J1[indice] != ';') def_j1 += tas_J1[indice++];
                def_j1 += ';';
                tas_J1.erase(i1+1,indice-i1);
                indice = i2+1;
                while(tas_J2[indice] != ';') def_j2 += tas_J2[indice++];
                def_j2 += ';';
                tas_J2.erase(i2+1,indice-i2);
            }

            tas_J1.erase(0,i1+1);
            tas_J2.erase(0,i2+1);
            n -= 4;
            m -= 4;
            bat++;
            goto here;

        }
        turn++;
        bat = 0;
        def_j1 = "";
        def_j2 = "";
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    if (n == 0) cout << 2 << " " << turn << endl;
    else if (m == 0) cout << 1 << " " << turn << endl;
    else cout << "PAT" << endl;
}