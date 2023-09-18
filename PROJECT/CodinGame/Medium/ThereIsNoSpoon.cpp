#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    string linear_plate;
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        linear_plate += line;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    int length_plate = width * height;
    int right_x = -1;
    int bot_y = -1;
    int y_index = 0;
    int i = 0;
    int line = 0;

    while ((i + line) < length_plate)
    {
        if (linear_plate[i+line] == '0')
        {
            /* Recherche d'un noeud a la droite du noeud trouvee */
            int j = i+1;
            while ( (right_x == -1) && (j < (width)) )
            {
                if (linear_plate[j+line] == '0') right_x = j;
                j++;
            }

            /* Recherche d'un noeud en dessous du noeud trouvee */
            j = i+line+width;
            while ( (bot_y == -1) && (j < length_plate))
            {
                if (linear_plate[j] == '0') bot_y = j - i;
                j += width;
            }

            /* Recherche de la ligne actuelle*/
            j = line;
            while (j>0)
            {
                j -= width;
                y_index++;
            }

            /* Fin de Recherche de la ligne actuelle*/

            /*Ecrituree des coordonnees de sortie*/

            cout << i << " " << y_index << " ";
            if (right_x != -1) cout << right_x << " " << y_index << " ";
            else cout << "-1 -1 ";

            if (bot_y != -1)
            {
                j = bot_y;
                y_index = 0;
                while (j > 0)
                {
                    j -= width;
                    y_index++;
                }
                cout << i << " " << y_index << endl;
            }
            else cout << "-1 -1" << endl;
            
            /*Fin d'ecrituree des coordonnees de sortie*/
            
        }

        if (width > 1)
        {
            if (right_x != -1) i = right_x; //Avance jusq'au prochain noeud
            else if (i == (width-1)) //Si on est en bout de rangee on change de ligne
            {
                i = 0;
                line += width;
            }
            else i++; //Avance dans la rangee
        }
        else
        {
            i = 0;
            line += width; //changement de ligne
        }

        bot_y = -1;
        right_x = -1;
        y_index = 0;
    }
    
    // Three coordinates: a node, its right neighbor, its bottom neighbor
}