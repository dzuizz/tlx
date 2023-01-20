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

const ll INF = 1e18;
const ll M = 1e9 + 7;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
ll pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll x = pow(a, b/2);
    if (b%2 == 0) return x*x;
    return x*x*a;
}

vector<vll> v, prefSum;

ll getSum(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return 0;
    return prefSum[r2][c2] - prefSum[r1 - 1][c2] - prefSum[r2][c1 - 1] + prefSum[r1 - 1][c1 - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m; cin >> n >> m;
    v.resize(n + 5, vll(m + 5, 0));
    prefSum.resize(n + 5, vll(m + 5, 0));
    
    FOR(i, 1, n + 1, 1) {
        FOR(j, 1, m + 1, 1) {
            cin >> v[i][j];
            
            prefSum[i][j] = prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1] + v[i][j];
        }
    }
    
    // n == 1
    ll ans = INF;
    // ll pref = 0;
    FOR(r1, 1, n+1, 1) {
        FOR(r2, r1, n+1, 1) {
            ll mini = INF; // mini = min(2*pref[l-1] - l)
            vll pref(m + 5, 0);
            FOR(j, 1, m+1, 1) {
                pref[j] = pref[j-1] + getSum(r1,j,r2,j); // "1 element"
                mini = min(mini, 2*pref[j-1] - j*(r2-r1+1));
                ll cost = getSum(r1, 1, r2, m) + (j+1)*(r2-r1+1) - 2*pref[j] + mini + getSum(1,1,r1-1,m) + getSum(r2+1,1,n,m);
                // cout << r1 << ' ' << r2 << ' ' << j << " -> " << prefSum[n][m] + (j+1)*(r2-r1+1) - 2*pref[j] + mini << '\n';
                ans = min(ans, cost);
            }
        }
    }
    
    cout << ans << '\n';
}
