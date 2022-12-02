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
const ll M = 1e9 + 7;

vector<vll> anc, edges;
ll LOG = 18; // log2(MAXN)
vector<vll> ab;
vll dep;

void dfs(ll cur) {
    each(nx, edges[cur]) {
        if (nx == anc[cur][0]) continue;
        
        anc[nx][0] = cur;
        dep[nx] = dep[cur] + 1;
        dfs(nx);
    }
}

ll LCA(ll u, ll v) {
    if (dep[u] < dep[v]) swap(u, v); // u bottom, v top
    
    RREP(i, LOG + 1) {
        if (dep[u] - (1<<i) < dep[v]) continue;
        u = anc[u][i];
    }
    
    if (u == v) return u;
    
    RREP(i, LOG + 1) {
        if (anc[u][i] == anc[v][i]) continue;
        u = anc[u][i]; v = anc[v][i];
    }
    
    return anc[u][0];
}

ll dist(ll u, ll v) {
    ll lca = LCA(u, v);
    
    return dep[u] + dep[v] - 2*dep[lca];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    
    edges.resize(n + 5);
    REP(i, n - 1) {
        ll u, v; cin >> u >> v;
        
        edges[u].pb(v);
        edges[v].pb(u);
    }
    
    ll m; cin >> m;
    
    ab.resize(m + 5, vll(2));
    FOR(i, 1, m + 1, 1) cin >> ab[i][0] >> ab[i][1];
    
    anc.resize(n + 5, vll(LOG + 5));
    dep.resize(n + 5);
    dep[1] = 0;
    dfs(1);
    
    FOR(j, 1, LOG + 1, 1) {
        FOR(i, 1, n + 1, 1) {
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    
    ll dp[m + 5][2];
    
    dp[m][0] = dp[m][1] = 0;
    ab[0][0] = ab[0][1] = 1;
    
    RFOR(i, 0, m, 1) {
        REP(j, 2) {
            if (i % 2) {
                dp[i][j] = min(
                    dp[i+1][0] + dist(ab[i][j], ab[i+1][0]) - dist(ab[i][(j+1)%2], ab[i+1][1]),
                    dp[i+1][1] + dist(ab[i][j], ab[i+1][1]) - dist(ab[i][(j+1)%2], ab[i+1][0])
                );
            } else {
                dp[i][j] = max(
                    dp[i+1][0] + dist(ab[i][j], ab[i+1][0]) - dist(ab[i][(j+1)%2], ab[i+1][1]),
                    dp[i+1][1] + dist(ab[i][j], ab[i+1][1]) - dist(ab[i][(j+1)%2], ab[i+1][0])
                );
            }
        }
    }
    
    ll ans = dp[0][0];
    if (ans > 0) cout << "Djowen " << ans << '\n';
    else if (ans < 0) cout << "Djonatan " << -ans << '\n';
    else cout << "Draw 0" << '\n';
}
