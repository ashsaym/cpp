#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct Team
{
    string Name;
    int Points;
    int Matches;
};

void Team_details(int Team_Numbers)
{
    Team t;
    t.Points = 0;
    t.Matches = 0;
    string Teams[] = {};
    int i,j;
    for(i=0;i<=Team_Numbers;i++)
    {
        cout << "\nEnter Team "<<i<<" name: ";
        cin >> t.Name;
        Teams[i] = {t.Name};
    }
    for(int j = 0; j < Team_Numbers; j++) {
        cout << Teams[j] << "\n";
    }
}

int main()
{
    int Team_Numbers;
    cout << "\nEnter Number of Teams : ";
    cin >> Team_Numbers;
    Team_details(Team_Numbers);
    return 0;
}