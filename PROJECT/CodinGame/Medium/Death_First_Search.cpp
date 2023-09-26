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
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();
    
    int node_link[1000][1000] = {0};
    int number_link[1000] = {0};
    int gate_way[1000] = {0};

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();
        node_link[n1][number_link[n1]++] = n2;
        node_link[n2][number_link[n2]++] = n1;
    }
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        gate_way[i] = ei;
    }

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        int copy_1 = number_link[si];
        for (int i = 0; i < e; i++)
        {
            for (int j = 0; j < copy_1; j++)
            {
                if (node_link[si][j] == gate_way[i])
                {
                    cout << to_string(si) + " " + to_string(gate_way[i]) << endl;
                    node_link[si][j] = -1;
                    goto here;
                }
            }
        }

        for (int i = 0; i < e; i++)
        {
            int pos_gate_way = gate_way[i];
            copy_1 = number_link[pos_gate_way];
            int j = 0;
            for (int j = 0; j < copy_1; j++)
            {
                if (node_link[pos_gate_way][j] != -1)
                {
                    cout << to_string(pos_gate_way) + " " + to_string(node_link[pos_gate_way][j]) << endl;
                    node_link[pos_gate_way][j] = -1;
                    goto here;
                }
            }
        }
        here : {};
        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        //cout << "0 1" << endl;
    }
}