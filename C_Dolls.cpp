#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define fi first
#define se second

const ll MAX_AI = 5e5;

pll dsu[MAX_AI+5];
map<ll, ll> m;
ll ans;

ll find(ll x) {
    if (dsu[x].fi == x) return x;
    return dsu[x].fi = find(dsu[x].fi);
}

void merge(ll a, ll b) {
    auto x = find(a), y = find(b);
    if (x == y) return;

    ans -= (dsu[x].se+1)/2;
    ans -= (dsu[y].se+1)/2;

    dsu[x].fi = y;
    dsu[y].se += dsu[x].se;
    
    ans += (dsu[y].se+1)/2;
}

int main() {
    ll n; cin >> n;

    for (ll i=0; i<=MAX_AI; i++) dsu[i] = make_pair(i, 1);

    for (ll i=0; i<n; i++) {
        ll x; cin >> x;
        if (m[x]) {
            cout << ans << " ";
            continue;
        }

        m[x] = 1; ans++;
        bool lf = m[x-1], rg = m[x+1];

        if (lf) merge(x-1, x);
        if (rg) merge(x, x+1);

        cout << ans << " ";
    }
}