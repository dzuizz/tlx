#include <iostream>
using namespace std;

int main(){
    int a, x;
    cin >> a >> x;
    cout << (x-x%a)/a << " " << x%a << endl;
}