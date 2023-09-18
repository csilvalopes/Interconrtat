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
    int surface_n; // the number of points used to draw the surface of Mars.
    cin >> surface_n; cin.ignore();
    for (int i = 0; i < surface_n; i++) {
        int land_x; // X coordinate of a surface point. (0 to 6999)
        int land_y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> land_x >> land_y; cin.ignore();
    }

    // game loop
    while (1) {
        int x;
        int y;
        int h_speed; // the horizontal speed (in m/s), can be negative.
        int v_speed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> x >> y >> h_speed >> v_speed >> fuel >> rotate >> power; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        cerr << v_speed << endl;
        
        if (abs(v_speed) < 26) cout << "0 0" << endl;
        else if (abs(v_speed) < 27) cout << "0 1" << endl;
        else if (abs(v_speed) <= 30) cout << "0 2" << endl;
        else if (abs(v_speed) <= 35) cout << "0 3" << endl;
        else cout << "0 4" << endl;

        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
    }
}