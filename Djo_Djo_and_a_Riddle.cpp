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
#define se second
#define FOR(i, a, b, inc) for (ll i = a; i < b; i += inc)
#define RFOR(i, a, b, inc) for (ll i = b - 1; i >= a; i -= inc)
#define REP(i, a) FOR(i, 0, a, 1)
#define RREP(i, a) RFOR(i, 0, a, 1)
#define each(a, x) for (auto& a: x)

const ll INF = 1e9;
const ll M = 1e9 + 7;

set<pll> segments; // (l,r) -> L = r-l+1, X = v[l]
vll segTree1, segTree2, v;
ll n, q;

void update(vll &segTree, ll idx, ll l, ll r, ll x, ll val) {
  if (l == r) {
    segTree[idx] += val;
    return;
  }
  
  ll mid = (l + r) / 2;
  
  if (x <= mid) update(segTree, idx*2, l, mid, x, val);
  else update(segTree, idx*2+1, mid+1, r, x, val);
  
  segTree[idx] = segTree[2*idx] + segTree[2*idx+1];
}

ll query(vll &segTree, ll idx, ll l, ll r, ll x, ll y) {
  if (x <= l && r <= y)
    return segTree[idx];
  if (r < x || l > y)
    return 0;
  
  ll mid = (l + r) / 2;
  
  return query(segTree, idx*2, l, mid, x, y) + query(segTree, idx*2+1, mid + 1, r, x, y);
}

void insertSegment(ll l, ll r) {
  segments.insert(pll(l, r));
  ll L = r-l+1, X = v[l]; // (L,X)
  
  update(segTree1, 1, 1, n, L, L*X);
  update(segTree2, 1, 1, n, L, X);
}

void eraseSegment(ll l, ll r) {
  segments.erase(pll(l, r));
  ll L = r-l+1, X = v[l]; // (L,X)
  
  update(segTree1, 1, 1, n, L, -L*X);
  update(segTree2, 1, 1, n, L, -X);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    
    v.resize(n + 5);
    segTree1.resize(4*n);
    segTree2.resize(4*n);

    ll l = 1;
    FOR(i, 1, n + 1, 1) {
      cin >> v[i];
      
      if (i > 1 && v[i] != v[i - 1]) {
        insertSegment(l,i-1);
        l = i;
      }
    }
    insertSegment(l,n);
    
    while (q--) {
      ll t; cin >> t;
      
      if (t == 1) {
        ll i, x; cin >> i >> x;
        
        auto it = segments.lower_bound({i+1, 0});
        pll rg = (it == segments.end() ? pll(-1, -1) : *it);
        pll seg = *(--it); // guaranteed
        pll lf = (it == segments.begin() ? pll(-1, -1) : *(--it));
        
        ll X = v[seg.fi];
        pll nx = {i, i};
                
        if (x == X) continue;
        
        eraseSegment(seg.fi, seg.se);
        
        if (rg.fi != -1 && x == v[rg.fi] && i == seg.se) {
          eraseSegment(rg.fi, rg.se);
          nx.se = rg.se;
        }
        
        if (lf.fi != -1 && x == v[lf.fi] && i == seg.fi) {
          eraseSegment(lf.fi, lf.se);
          nx.fi = lf.fi;
        }
        
        v[i] = x;
        
        if (seg.fi < nx.fi) insertSegment(seg.fi, nx.fi-1);
        if (nx.se < seg.se) insertSegment(nx.se+1, seg.se);
        
        insertSegment(nx.fi, nx.se);
      } else {
        ll k; cin >> k;
        
        ll LX = query(segTree1, 1, 1, n, k, n);
        ll X = query(segTree2, 1, 1, n, k, n);
        
        ll ans = k * LX + (-k*k + k) * X;
        cout << ans << '\n';
      }
    }
}
