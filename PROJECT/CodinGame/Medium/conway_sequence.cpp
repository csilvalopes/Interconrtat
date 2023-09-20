#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define a_size 20000

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int r;
    cin >> r; cin.ignore();
    int l;
    cin >> l; cin.ignore();

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    int i = 0;
    int index = 1;
    int tab[a_size];
    int last_index = 2;

    cerr << r << "  " << l << endl << endl;

    for (i = 0; i < l; i++)
    {
        if (i == 0) tab[0] = r;
        if (i == 1)
        {
            tab[0] = 1;
            tab[1] = r;
            index++;
        }
        if (i > 1)
        {
            int last_int = tab[0];
            int int_to_write = 1;
            int new_tab[a_size];
            index = 0;
            for (int j = 1; j < last_index; j++)
            {
                int test = tab[j];
                if (test == last_int) int_to_write++;
                else
                {
                    new_tab[index++] = int_to_write;
                    new_tab[index++] = last_int;
                    int_to_write = 1;
                    last_int = test;
                }
            }
            if (int_to_write)
            {
                new_tab[index++] = int_to_write;
                new_tab[index++] = last_int;
            }
            for (int j = 0; j < index; j++) tab[j] = new_tab[j];
            last_index = index;
        }
    }

    string current_line;
    for (int j = 0; j < index; j++) current_line += to_string(tab[j]) + " ";
    current_line.pop_back();

    cout << current_line << endl;
}