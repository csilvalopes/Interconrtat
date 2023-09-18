#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    int thor_pos_x = initial_tx;
    int thor_pos_y = initial_ty;
    int score = 0;
    // game loop
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns; cin.ignore();
        score = 0;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        if (light_x > thor_pos_x) score += 10;
        else if (light_x == thor_pos_x) score += 20;

        if (light_y > thor_pos_y) score += 1;
        else if (light_y == thor_pos_y) score +=2;
        cerr << "Score = " << score << endl;
        switch (score)
        {
            case 0:
                thor_pos_x--;
                thor_pos_y--;
                cout << "NW" << endl;
                break;
                
            case 1:
                thor_pos_x--;
                thor_pos_y++;
                cout << "SW" << endl;
                break;

            case 2:
                thor_pos_x--;
                cout << "W" << endl;
                break;

            case 10:
                thor_pos_x++;
                thor_pos_y--;
                cout << "NE" << endl;
                break;
                
            case 11:
                thor_pos_x++;
                thor_pos_y++;
                cout << "SE" << endl;
                break;

            case 12:
                thor_pos_x++;
                cout << "E" << endl;
                break;

            case 20:
                thor_pos_y--;
                cout << "N" << endl;
                break;
                
            case 21:
                thor_pos_y++;
                cout << "S" << endl;
                break;

            case 22:
                break;
            default:
                //expression
                break;
        }

        // A single line providing the move to be made: N NE E SE S SW W or NW
        //cout << "SE" << endl;
    }
}