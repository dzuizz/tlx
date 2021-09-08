#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    if(n<0) cout << (1+2*abs(n))*abs(n) << endl;
    else cout << n*(2*n-1) << endl;
}