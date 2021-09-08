#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, s=-1, b=-1, a=0;
    cin >> n >> m;
    if(n<=5*m && n>=m){
        a = 5*m-n;
        if(a>=m) s = 0;
        else s = m-a;
        b = m-ceil(a/4.0);
    }
    cout << s << " " << b << endl;
}