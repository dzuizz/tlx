#include <iostream>
using namespace std;

int main(){
    int p, q;
    cin >> p >> q;
    if ((p*p+q*q+1)%4 == 0){
        cout << (p*p+q*q+1)/4 << endl;
    } else {
        cout << -1 << endl;
    }
}