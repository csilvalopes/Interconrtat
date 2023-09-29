#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void giving_money(const vector<int> tab_money, const int budget)
{
    int needed_money = budget;
    int tab_size = tab_money.size();
    int out = 0;
    for (int i = 0; i < tab_size; i++)
    {   
        int mean_money = needed_money/(tab_size - i);
        if (i == tab_size - 1) out = needed_money;
        else if (mean_money > tab_money[i]) out = tab_money[i];
        else out = mean_money;
        cout << out << endl;
        needed_money -= out;
    }
};

int main()
{
    int n;
    cin >> n; cin.ignore();
    cerr << "Nombre de participant -> " << n << endl;
    int c;
    cin >> c; cin.ignore();
    int sum = 0;
    vector<int> my_tab;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b; cin.ignore();
        sum += b;
        my_tab.push_back(b);
    }
    sort(my_tab.begin(), my_tab.end());

    //for (int i = 0; i < my_tab.size(); i++) cerr << my_tab[i] << endl;

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if (sum < c) cout << "IMPOSSIBLE" << endl;
    else giving_money(my_tab, c);
}