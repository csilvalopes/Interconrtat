#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int l;
    cin >> l; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    string t;
    string concatenate_art;
    getline(cin, t);
    for (int i = 0; i < h; i++) {
        string row;
        getline(cin, row);
        concatenate_art += row;
    }
    
    int tab_answer[t.size()];
    for (int i = 0; i < t.size(); i++)
    {
        char value = t[i];
        if ((value >= 65) && (value <= 90)) tab_answer[i] = value - 65;
        else if ((value >= 97) && (value <= 122)) tab_answer[i] = value - 97;
        else tab_answer[i] = 26;
    }

    for (int i = 0; i < h; i++)
    {
    string answer;
        for (int j = 0; j < t.size(); j++)
        {
            if (tab_answer[j] != 26)
            {
                answer += concatenate_art.substr(l*tab_answer[j] + l*i*27,l);
            }
            else
            {
                answer += concatenate_art.substr(l*26 + l*i*27,l);
            }
        }
        cout << answer << endl;
    }
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "answer" << endl;
}