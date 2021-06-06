#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 0, y = 0;
    string s;
    cin >> s;
    for (int i = 0; i <= s.length(); i++)
    {
        switch (s[i])
        {
        case 'R':
            x++;
            break;
        case 'L':
            x--;
            break;
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        }
    }
    cout << x << " " << y << endl;
}