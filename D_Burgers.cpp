#include<iostream>
using namespace std;
typedef long long ll;

const ll INF = 1e9;

int main() {
    ll n; cin >> n;
    ll x[n], a[n], b[n];

    for (ll i=0; i<n; i++) cin >> x[i];
    for (ll i=0; i<n; i++) cin >> a[i];
    for (ll i=0; i<n; i++) cin >> b[i];

    ll l=0, r=INF+2;

    while (l < r) {
        ll m = (l+r+1)/2;
        
        bool flag = 1;
        ll resA = INF, resB = INF;
        
        for (ll i=0; i<n; i++) {
            ll totalDiff, indivDiff;
            
            if (a[i] < b[i]) {
                totalDiff = x[i] - a[i]*m, indivDiff = b[i] - a[i];
                
                resA = min(resA, m);
                resB = min(resB, totalDiff/indivDiff);
            } else if (a[i] > b[i]) {
                totalDiff = x[i] - b[i]*m, indivDiff = a[i] - b[i];
                
                resA = min(resA, totalDiff/indivDiff);
                resB = min(resB, m);
            } else {
                totalDiff = x[i] - a[i]*m;
                
                resA = min(resA, m);
                resB = min(resB, m);
            }
            
            if (totalDiff < 0) {
                flag = 0;
                break;
            }
        }
        
        if (!flag || resA + resB < m) r = m - 1;
        else l = m;
    }
    
    cout << l << '\n';
}
