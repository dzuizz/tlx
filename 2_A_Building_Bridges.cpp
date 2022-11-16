#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <cassert>
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

struct Node {
    ll nx;
    priority_queue<pll, vector<pll>, greater<pll> > cc;
};

const ll INF = 1e9;
const ll M = 1e9 + 7;

priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<Node> dsu;
vll numOfChosen;
ll n, m, q, sum;
vll u, v, h;

ll find(ll x) {
    if (dsu[x].nx == x) return x;
    return dsu[x].nx = find(dsu[x].nx);
}

void merge(ll a, ll b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz(dsu[b].cc) > sz(dsu[a].cc)) swap(a, b);
    
    dsu[b].nx = a;
    while (!dsu[b].cc.empty()) {
        dsu[a].cc.push(dsu[b].cc.top());
        dsu[b].cc.pop();
    }
}

bool cmp(ll a, ll b) {
    a = find(a); b = find(b);
    return numOfChosen[a] > numOfChosen[b];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    
    dsu.resize(n + 5);
    u = v = vll(m + 5);
    numOfChosen = h = vll(n + 5, 0);
    
    FOR(i, 1, n + 1, 1) {
        cin >> h[i];
        pq.push(pll(h[i], i));
        
        dsu[i].nx = i;
        dsu[i].cc.push(pll(h[i], i));
    }

    FOR(i, 1, m + 1, 1) {
        cin >> u[i] >> v[i];
        merge(u[i], v[i]);
    }
    
    sll s;
    vb vis(n + 5, 0);

    FOR(i, 1, n + 1, 1) {
        ll x = find(i);
        ll sz = sz(s);
        
        s.insert(x);
        if (sz == sz(s)) continue;
        pll cur = dsu[x].cc.top();
        
        sum += cur.fi;
        vis[cur.se] = 1;
        numOfChosen[x]++;
    }
    
    ll numOfCC = sz(s);
    ll numOfEdges = numOfCC - 1;
    ll numOfNodes = numOfEdges * 2;
    
    if (numOfNodes > n) {
        cout << "-1\n";
        return 0;
    }
    
    REP(i, numOfNodes - sz(s)) {
        while (vis[pq.top().se]) pq.pop();
        numOfChosen[find(pq.top().se)]++;
        sum += pq.top().fi; pq.pop();
    }
    
    vb isConnected(n + 5, 0);
    
    vll v;
    each(x, s)
        v.pb(x);
    sort(all(v), cmp);
    
    ll test = 0;
    vpll ans;
    FOR(i, 1, sz(v), 1) {
        ll x1 = find(v[i]);
        ll x2 = find(v[i - 1]);
        
        ll y1 = dsu[x1].cc.top().se; //.lowest node from x1
        ll y2 = dsu[x2].cc.top().se; //.lowest node from x2
        dsu[x1].cc.pop(); dsu[x2].cc.pop();
        
        test += h[y1] + h[y2];
        
        merge(x1, x2);
        
        ans.pb({y1, y2});
    }
    cout << test << '\n';
    
    if (q == 1) {
      cout << sz(ans) << '\n';
        each(x, ans) {
          cout << x.fi << " " << x.se << '\n';
        }
    }
}
