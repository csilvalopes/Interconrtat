#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum dir {RIGHT = 0, LEFT};

string try_to_exit_floor(const int _clone_pos, const int _clone_floor, const int _exit_pos, const string _direction, int * tab_clone, const int _width)
{
    string out;
    int *copy_tab = tab_clone;
    if (_clone_pos == _exit_pos) out = "WAIT";
    else if (_clone_pos > _exit_pos)
    {
        if (_direction == "LEFT")
        {
            out = "WAIT";
        }
        else
        {
            if ((copy_tab[_clone_floor] > _clone_pos) && (_clone_pos < (_width - 1)))
            {
                out = "WAIT";
            }
            else
            {
                copy_tab[_clone_floor] = _clone_pos;
                out = "BLOCK";
            }
        }
    }
    else
    {
        if (_direction == "RIGHT")
        {
            out = "WAIT";
        }
        else
        {
            if ((copy_tab[_clone_floor] < _clone_pos) && (copy_tab[_clone_floor] != -1))
            {
                out = "WAIT";
            }
            else
            {
                copy_tab[_clone_floor] = _clone_pos;
                out = "BLOCK";
            }
        }
    }
    tab_clone = copy_tab;
    return out;
};

int main()
{
    int nb_floors; // number of floors
    int width; // width of the area
    int nb_rounds; // maximum number of rounds
    int exit_floor; // floor on which the exit is found
    int exit_pos; // position of the exit on its floor
    int nb_total_clones; // number of generated clones
    int nb_additional_elevators; // ignore (always zero)
    int nb_elevators; // number of elevators
    cin >> nb_floors >> width >> nb_rounds >> exit_floor >> exit_pos >> nb_total_clones >> nb_additional_elevators >> nb_elevators; cin.ignore();
    int tab_elevator_pos[nb_elevators];
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor; // floor on which this elevator is found
        int elevator_pos; // position of the elevator on its floor
        cin >> elevator_floor >> elevator_pos; cin.ignore();
        tab_elevator_pos[elevator_floor] = elevator_pos;
    }
    int blocked_clone[nb_floors];

    for (int i = 0; i < nb_floors; i++)
    {
        blocked_clone[i] = -1;
    }
    
    // game loop
    while (1) {
        int clone_floor; // floor of the leading clone
        int clone_pos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> clone_floor >> clone_pos >> direction; cin.ignore();
        cerr << clone_floor << " " << clone_pos << " " << direction;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        if (clone_floor == -1)
        {
            cout << "WAIT" <<endl;
        }
        else if (exit_floor == clone_floor)
        {
            cout << try_to_exit_floor(clone_pos, clone_floor, exit_pos, direction, blocked_clone, width) << endl;
        }
        else
        {
            cout << try_to_exit_floor(clone_pos, clone_floor, tab_elevator_pos[clone_floor], direction, blocked_clone, width) << endl;
        }

        //cout << "WAIT" << endl; // action: WAIT or BLOCK
    }
}