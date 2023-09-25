#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int search_start_pos(const string a_plate, const int lenght_plate)
{
    int start_pos = 1;
    int actual_line = 1;
    char test = a_plate[start_pos + actual_line * lenght_plate];
    while ( test != '@')
    {
        if (start_pos == lenght_plate-2)
        {
            start_pos = 1;
            actual_line++;
        }
        else start_pos++;
        test = a_plate[start_pos + actual_line * lenght_plate];
    }
    return start_pos + actual_line * lenght_plate;
};

int next_blunder_dir (const string a_plate, const int linear_pos, const int lenght_plate, const bool blunder_state)
{
    
    if (blunder_state)
    {
        if ((a_plate[linear_pos + lenght_plate] != '#') && (a_plate[linear_pos + lenght_plate] != 'X')) return 0;
        else if ( (a_plate[linear_pos + 1] != '#') && (a_plate[linear_pos + 1] != 'X')) return 1;
        else if ( (a_plate[linear_pos - lenght_plate] != '#') && (a_plate[linear_pos - lenght_plate] != 'X')) return 2;
        else return 3;
    }
    else
    {
        if ((a_plate[linear_pos - 1] != '#') && (a_plate[linear_pos - 1] != 'X')) return 3;
        else if ( (a_plate[linear_pos - lenght_plate] != '#') && (a_plate[linear_pos - lenght_plate] != 'X')) return 2;
        else if ( (a_plate[linear_pos + 1] != '#') && (a_plate[linear_pos + 1] != 'X')) return 1;
        else return 0;
    }
    return 0;
};

int next_blunder_pos (const int actual_pos, const int lenght_plate, const int dir)
{        
    switch (dir)
        {
            case 0: return actual_pos + lenght_plate;
            case 1: return actual_pos + 1;
            case 2: return actual_pos - lenght_plate;
            case 3: return actual_pos - 1;
            default:
            break;
        };
    return 0;
};

bool obstruction_sir(const int actual_pos, const int lenght_plate, const int dir, string *a_plate, const bool rage)
{
    string copy = *a_plate;
    bool out = false;
    if (!rage)
    {
        switch (dir)
            {
                case 0: if ( (copy[actual_pos + lenght_plate] == '#') || (copy[actual_pos + lenght_plate] == 'X') ) out = true;
                break;
                case 1: if ( (copy[actual_pos + 1] == '#') || (copy[actual_pos + 1] == 'X')) out = true;
                break;
                case 2: if ( (copy[actual_pos - lenght_plate] == '#') || (copy[actual_pos - lenght_plate] == 'X') ) out = true;
                break;
                case 3: if ( (copy[actual_pos - 1] == '#') || (copy[actual_pos - 1] == 'X') ) out = true;
                break;
                default:
                break;
            };
    }
    else
    {
        switch (dir)
            {
                case 0: if ( copy[actual_pos + lenght_plate] == '#' ) out =  true;
                        if ( copy[actual_pos + lenght_plate] == 'X' )
                        {
                            copy[actual_pos + lenght_plate] = ' ';
                            out =  false;
                        }
                break;
                case 1: if ( copy[actual_pos + 1] == '#' ) out =  true;
                        if ( copy[actual_pos + 1] == 'X' )
                        {
                            copy[actual_pos + 1] = ' ';
                            out =  false;
                        }
                break;
                case 2: if ( copy[actual_pos - lenght_plate] == '#') out =  true;
                        if ( copy[actual_pos - lenght_plate] == 'X')
                        {
                            copy[actual_pos - lenght_plate] = ' ';
                            out =  false;
                        }
                break;
                case 3: if ( copy[actual_pos - 1] == '#' ) out =  true;
                        if ( copy[actual_pos - 1] == 'X' )
                        {
                            copy[actual_pos - lenght_plate] = ' ';
                            out =  false;
                        }
                break;
                default:
                break;
            };
    }
    *a_plate = copy;
    return out;
};

void search_teleport(const string a_plate, const int l, const int c, int *tab)
{
    int i = c+1;
    int lenght = l*c;
    while ((a_plate[i++] != 'T') && (i < lenght)) tab[0] = i;
    while ((a_plate[i++] != 'T') && (i < lenght)) tab[1] = i;

};

int main()
{
    int l;
    int c;
    cin >> l >> c; cin.ignore();
    string linear_plate;
    for (int i = 0; i < l; i++) {
        string row;
        getline(cin, row);
        //cerr << row << endl;
        linear_plate += row;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int teleporters[2];
    teleporters[0] = 0;
    teleporters[1] = 0;

    search_teleport(linear_plate, l, c, teleporters);


    int blunder_start = search_start_pos(linear_plate,c);
    int blunder_pos = blunder_start;
    bool blunder_rage = false;
    bool priorities_base = true;
    string blunder_dir_str[4] = {"SOUTH", "EAST", "NORTH", "WEST"};
    int blunder_dir = 0;
    string tab[1000];
    int last_dir = -1, last_last_dir = -2, last_last_last_dir = -3;
    int count = 0, last_count = -14, last_last_count = -6, last_last_last_count = 90;
    int index = 0;

    while (1)
    {
        //cerr << blunder_dir << endl;
        switch (linear_plate[blunder_pos])
        {
            case '$':
            for (int i = 0; i < index; i++) cout << tab[i] << endl;
            return 42;
            break;
            case 'S':
                blunder_dir = 0;
                if (blunder_rage && (linear_plate[blunder_pos + c] == 'X') ) linear_plate[blunder_pos + c] = ' ';
                blunder_pos = next_blunder_pos(blunder_pos, c, blunder_dir);
                tab[index++] = blunder_dir_str[blunder_dir];
            break;
            case 'E':
                blunder_dir = 1;
                if (blunder_rage && (linear_plate[blunder_pos + 1] == 'X')) linear_plate[blunder_pos + 1] = ' ';
                blunder_pos = next_blunder_pos(blunder_pos, c, blunder_dir);
                tab[index++] = blunder_dir_str[blunder_dir];
            break;
            case 'N':
                blunder_dir = 2;
                if (blunder_rage && (linear_plate[blunder_pos - c] == 'X')) linear_plate[blunder_pos - c] = ' ';
                blunder_pos = next_blunder_pos(blunder_pos, c, blunder_dir);
                tab[index++] = blunder_dir_str[blunder_dir];
            break;
            case 'W':
                blunder_dir = 3;
                if (blunder_rage && (linear_plate[blunder_pos - 1] == 'X')) linear_plate[blunder_pos - 1] = ' ';
                blunder_pos = next_blunder_pos(blunder_pos, c, blunder_dir);
                tab[index++] = blunder_dir_str[blunder_dir];
            break;
            case 'I':
            priorities_base = !priorities_base;
            goto here;
            break;
            case 'B':
            blunder_rage = !blunder_rage;
            goto here;
            break;
            case 'T':
                if (blunder_pos == teleporters[0]) blunder_pos = teleporters[1];
                else blunder_pos = teleporters[0];
                goto here;
            break;
            default:
                here:{};
                if (obstruction_sir(blunder_pos, c, blunder_dir, &linear_plate, blunder_rage))
                {
                    last_last_last_dir = last_last_dir;
                    last_last_dir = last_dir;
                    last_dir = blunder_dir;
                    blunder_dir = next_blunder_dir(linear_plate, blunder_pos, c, priorities_base);
                    last_last_last_count = last_last_count;
                    last_last_count = last_count;
                    last_count = count;
                    count = 0;
                }
                blunder_pos = next_blunder_pos(blunder_pos, c, blunder_dir);
                tab[index++] = blunder_dir_str[blunder_dir];
                count++;
            break;
        };
        if ((last_last_last_dir == last_dir) && (blunder_dir == last_last_dir) && (last_last_last_count == last_count) && (count == last_last_count)) goto out;
    }

    out : cout << "LOOP" << endl;
}