#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

string encode_message (const string message_to_encode, const string * tab_rotor, const int rand_number)
{
    int message_size = message_to_encode.size();
    string message_out[4];

    for (int i = 0; i < message_size; i++)
    {
        int new_char =  (int)message_to_encode[i] + rand_number + i;
        if (new_char <= 90) message_out[0] += (char)new_char;
        else 
        {
            while (new_char > 90) new_char -= 26;
            message_out[0] += (char)new_char;
        }

    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < message_size; j++)
        {
            message_out[i+1] += tab_rotor[i][message_out[i][j] - 65];
        }
    }
    return message_out[3];
};

string decode_message(const string message_to_decode, const string * tab_rotor, const int rand_number)
{
    int message_size = message_to_decode.size();
    string message_out[5];
    message_out[0] = message_to_decode;

    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i <message_size; i++)
        {
            int j = 0;
            while(message_out[k][i] != tab_rotor[2-k][j]) j++;
            message_out[k+1] += j + 65;
        }
    }

    for (int i = 0; i < message_size; i++)
    {
        char test = message_out[3][i] - rand_number - i;
        while (test < 65) test += 26;
        message_out[4] += test;
    }

    return message_out[4];
};

int main()
{
    string operation;
    getline(cin, operation);
    int pseudo_random_number;
    cin >> pseudo_random_number; cin.ignore();
    string tab_rotor[3];
    for (int i = 0; i < 3; i++) {
        string rotor;
        getline(cin, rotor);
        tab_rotor[i] = rotor;
    }
    string message;
    getline(cin, message);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if (operation == "ENCODE")
    {
    cout << encode_message(message, tab_rotor, pseudo_random_number) << endl;
    }
    else
    {
    cout << decode_message(message, tab_rotor, pseudo_random_number) << endl;
    }

}