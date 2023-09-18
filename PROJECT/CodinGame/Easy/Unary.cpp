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
    string message;
    getline(cin, message);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int number = 0;
    int last_byte = -1;
    char dislock_char;
    int j = -1;
    for (int i = 0; i < 7*message.size(); i++)
    {
        if ((i % 7) == 0)
        {
            j++;
            dislock_char = message[j];
        }
        int test = (dislock_char & 0b1000000) >> 6;

        if (last_byte == -1) last_byte = test;
        
        if (test == last_byte) number++;
        else 
        {
            if (last_byte) cout << "0 ";
            else cout << "00 ";
            for (int i = 0; i < number; i++) cout << "0";
            cout << " ";
            number = 1;
        }

        if (test) last_byte = test;
        else last_byte = 0;

        dislock_char = dislock_char << 1;
    }
    
    if (last_byte) cout << "0 ";
    else cout << "00 ";
    for (int i = 0; i < number; i++) cout << "0";

    cout << endl;
}