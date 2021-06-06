#include <iostream>
using namespace std;
int main()
{
    int n, m, r = 1;
    cin >> n >> m;
    for (int i = 1; i < n * m; i++)
    {
        r *= 2;
        r %= 998244353;
    }
    cout << r << endl;
}