#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef map<ll, ll> mll;
typedef set<ll> sll;
typedef queue<ll> qll;
typedef queue<pll> qpll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define fr front()
#define bk back()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define FOR(i, a, b, inc) for (ll i = a; i < b; i += inc)
#define RFOR(i, a, b, inc) for (ll i = b - 1; i >= a; i -= inc)
#define REP(i, a) FOR(i, 0, a, 1)
#define RREP(i, a) RFOR(i, 0, a, 1)
#define each(a, x) for (auto& a: x)

const ll INF = 1e9;
const ll M = 998244353;
const ll MAXN = 1e6;

vector<vpll> edges;
vll fac, inv;

ll mul(ll a, ll b) {
    a %= M; b %= M;
    return (a * b) % M;
}

ll pow(ll a, ll b) {
    if (b == 0) return 1;
    ll x = pow(a, b/2);
    if (b%2 == 0) return mul(x, x);
    return mul(mul(x, x), a);
}

ll func(ll cur, ll prev) {
    ll a = 0, b = 1, res = 1;
    
    each(x, edges[cur]) {
        if (x.fi == prev) {
            a += x.se - 1;
            b = mul(b, inv[x.se - 1]);
        } else {
            b = mul(b, inv[x.se]);
            a += x.se;
            
            res = mul(res, func(x.fi, cur));
        }
    }
    
    return mul(mul(fac[a], b), res);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    
    edges.resize(n + 5);
    fac.resize(MAXN + 5);
    inv.resize(MAXN + 5);
    
    fac[0] = 1;
    FOR(i, 1, MAXN + 1, 1)
        fac[i] = mul(fac[i - 1], i);
    inv[0] = 1;
    FOR(i, 1, MAXN + 1, 1)
        inv[i] = pow(fac[i], M-2) % M; 
    
    REP(i, n - 1) {
        ll u, v, w; cin >> u >> v >> w; w /= 2;
        
        edges[u].pb({v, w});
        edges[v].pb({u, w});
    }
    
    cout << func(1, 0) << '\n';
}
