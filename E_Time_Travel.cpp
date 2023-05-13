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

struct Segment {
    ll xx, xz, zx, zz, sum;
    Segment(ll a=0, ll b=0, ll c=0, ll d=0, ll e=0): xx(a), xz(b), zx(c), zz(d), sum(e) {}
};

const ll INF = 1e9;
const ll M = 1e9 + 7;

vector<Segment> segTree;
string s;
ll n;

Segment merge(Segment &l, Segment &r) {
    Segment res;
    
    res.xx = (l.xx + r.xx + (l.xz*r.xx)%M + (l.xx*r.zx)%M)%M;
    res.xz = (l.xz + r.xz + (l.xx*r.zz)%M + (l.xz*r.xz)%M)%M;
    res.zx = (l.zx + r.zx + (l.zx*r.zx)%M + (l.zz*r.xx)%M)%M;
    res.zz = (l.zz + r.zz + (l.zx*r.zz)%M + (l.zz*r.xz)%M)%M;
    res.sum = (res.xx + res.xz + res.zx + res.zz)%M;
    
    return res;
}

void build(ll idx, ll l, ll r) {
    if (l == r) {
        if (s[l] == 'x') segTree[idx].xx = 1;
        else segTree[idx].zz = 1;
        
        return;
    }
    
    ll mid = (l+r) / 2;
    build(2*idx, l, mid);
    build(2*idx + 1, mid+1, r);

    segTree[idx] = merge(segTree[2*idx], segTree[2*idx+1]);
}

void update(ll idx, ll l, ll r, ll x) {
    if (l == r) {
        segTree[idx].xx = 1 - segTree[idx].xx;
        segTree[idx].zz = 1 - segTree[idx].zz;
        return;
    }
    
    ll mid = (l+r) / 2;
    
    if (x <= mid) update(2*idx, l, mid, x);
    else update(2*idx+1, mid+1, r, x);

    segTree[idx] = merge(segTree[2*idx], segTree[2*idx+1]);
}

Segment query(ll idx, ll l, ll r, ll x, ll y) {
    if (x <= l && r <= y) {
        return segTree[idx];
    }
    if (l > y || r < x) {
        return Segment();
    }
    
    ll mid = (l+r) / 2;
    Segment lf = query(2*idx, l, mid, x, y);
    Segment rg = query(2*idx+1, mid+1, r, x, y);
    return merge(lf, rg);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    n = sz(s);
    segTree = vector<Segment>(4*n);
    
    build(1, 0, n-1);
    
    ll q; cin >> q;
    while (q--) {
        char ch; cin >> ch;
        
        if (ch == 'U') {
            ll x; cin >> x; x--;
            update(1, 0, n-1, x);
        } else {
            ll x, y; cin >> x >> y; x--, y--;
            Segment ans = query(1, 0, n-1, x, y);
            cout << ans.sum << '\n';
        }
    }
}
