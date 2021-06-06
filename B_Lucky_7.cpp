#include <iostream>
using namespace std;

int main()
{
    int n, i = 2;
    cin >> n;
    while (true)
    {
        if ((n - 1) % i == 0)
        {
            break;
        }
        i++;
    }
    cout << i << endl;
    for(int a=0;a<i;a++){
        if (a==i-1){
            cout << (n-1)/i+1 << endl;
        } else {
            cout << (n-1)/i << " ";
        }
    }
}