/*********************************HEADER**********************************

Jamboard : https://jamboard.google.com/d/1sJt51tfL7o2SpnsceJ_SHVXMnuV3VORSMH0kRF_QzYo/viewer?f=1

Problem : https://vjudge.net/contest/484765
https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3a1c

https://uhunt.onlinejudge.org/

Segment Tree
Example : {
  array: https://ideone.com/LJJJB9 ,
  poller: https://ideone.com/dyJ2kv
}

Convex Hull
Example : https://ideone.com/0JIY6q

Matrix Exponentiation : https://ideone.com/uDCb6o
Contest : https://vjudge.net/contest/488578

Intersections:
Example : https://ideone.com/Gcj0Fu
https://www.spoj.com/problems/HORRIBLE/

https://vjudge.net/contest/467726#overview

https://tlx.toki.id/problems/compfest-13-scpc-penyisihan/I
https://atcoder.jp/contests/arc076/tasks/arc076_d

https://tlx.toki.id/problems/osn-2022/2A/

https://tlx.toki.id/problems/bnpchs-2022-penyisihan

https://tlx.toki.id/problems/inc-2020/G

https://tlx.toki.id/problems/icpc-jakarta-2021/M

https://tlx.toki.id/problems/icpc-jakarta-2021/D

https://tlx.toki.id/problems/sg-noi-2014/A

https://tlx.toki.id/problems/sg-noi-2014/B

**************************************************************************/

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

// typedef long long ll;
#define ll long long 

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

struct Edge {
    ll weight;
    pll nodes;
    
    bool operator < (Edge &oth) {
        // this < oth 
        return weight > oth.weight;
    }
};

struct Node {
    ll parent, size = 1;
    vll v;
};

const ll INF = 1e18;
const ll M = 1e9 + 7;

vector<Edge> edges;
ll n, e, q;
vector<Node> dsu;
// size, members 
vll ans;
ll cur;

ll find(ll n) {
    if (n == dsu[n].parent) return n;
    return dsu[n].parent = find(dsu[n].parent);
}

void merge(ll a, ll x) {
    a = find(a); ll b = find(x);
    // cout << ">> " << a << ' ' << x << '\n';
    if (a == b) return;
    
    if (dsu[a].size < dsu[b].size) swap(a, b);
    // if (b == 1) swap(a, b); //
    
    
    if (find(b) == find(1)) {
        // cout << "HERE\n";
        each(x, dsu[a].v) {
            ans[x] = cur;
        }
    }
    if (find(a) == find(1)) {   
        // cout << "HERE\n";
        each(x, dsu[b].v) {
            ans[x] = cur;
        }
    }
    
    dsu[b].parent = a;
    dsu[a].size += dsu[b].size;
    
    each(x, dsu[b].v) {
        dsu[a].v.pb(x);
    }
    
    // return ((a == 1 || b == 1) ? x : 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> e >> q;
    
    dsu.resize(n + 5);
    FOR(i, 1, n + 1, 1) {
        dsu[i].parent = i;
        dsu[i].v.pb(i);
    }
    ans.resize(n + 5);
    
    REP(i, e) {
        ll u, v, w; cin >> u >> v >> w;
        
        edges.pb({w, {u, v}});
    }
    sort(all(edges));
    
    for (Edge edge : edges) {
        ll weight = edge.weight;
        ll a = edge.nodes.fi;
        ll b = edge.nodes.se;
        
        cur = weight;
        
        merge(a, b);
        // ans[merge(a, b)] = cur;
    }
    
    while (q--) {
        ll x; cin >> x;
        cout << ans[x] << '\n';
    }
}
