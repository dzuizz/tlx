#include <iostream>
using namespace std;

int main()
{
    int n;
    int l[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    cin >> n;
    for (int i = 0; n > 0; i++)
    {
        int x = 0;
        if (n >= l[i])
        {
            while (n >= l[i])
            {
                n -= l[i];
                x++;
            }
            cout << l[i] << " " << x << endl;
        }
    }
}