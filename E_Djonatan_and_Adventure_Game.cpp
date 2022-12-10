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
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> Node;
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
#define x second
#define a fi.fi
#define b fi.x
#define FOR(i, a, b, inc) for (ll i = a; i < b; i += inc)
#define RFOR(i, a, b, inc) for (ll i = b - 1; i >= a; i -= inc)
#define REP(i, a) FOR(i, 0, a, 1)
#define RREP(i, a) RFOR(i, 0, a, 1)
#define each(a, x) for (auto& a: x)

const ll INF = 1e9;
const ll M = 1e9 + 7;

bool cmp(Node u, Node v) {
    if (u.a != v.a) return u.a > v.a;
    return u.b > v.b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, u; cin >> n >> u;
    vector<Node> v(n);
    
    REP(i, n)
        cin >> v[i].a >> v[i].b >> v[i].x;
      
    sort(all(v), cmp);
    ll dp[n][u + 1]; memset(dp, 0, sizeof(dp));
    
    ll cur = u, cnt = 1;
    while (cur >= v[0].a) {
        cur -= v[0].a - v[0].b;
        dp[0][cur] = v[0].x * cnt++;
    }
    
    FOR(i, 1, n, 1) {
        RFOR(j, 0, u + 1, 1) {
            dp[i][j] = dp[i-1][j];
            if (j - v[i].b >= 0 && j - v[i].b + v[i].a <= u) {
                dp[i][j] = max(dp[i][j], dp[i][j-v[i].b+v[i].a] + v[i].x);
            }
        }
    }
    
    ll x = 0, y = 0;
    REP(i, n) {
        REP(j, u + 1) {
            if (dp[i][j] >= dp[x][y])
                x = i, y = j;
        }
    }
    
    cout << dp[x][y] << " " << y << '\n';
}
