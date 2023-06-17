#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

struct Segment {
    ll sum=0, mx=0;
    Segment *lf, *rg;
    
    Segment(ll a=0, ll b=0): sum(a), mx(b) {}
};

Segment *root;
vector<ll> v;

void build(Segment *seg, ll l, ll r) {
    if (l == r) {
        seg->sum = v[l];
        seg->mx = v[l];
        return;
    }
    
    ll m = (l+r)/2;
    
    seg->lf = new Segment(); build(seg->lf, l, m);
    seg->rg = new Segment(); build(seg->rg, m + 1, r);
    
    seg->sum = seg->lf->sum + seg->rg->sum;
    seg->mx = max(seg->lf->mx, seg->rg->mx);
}

ll query(Segment *seg, ll l, ll r, ll x, ll y) {
    if (x <= l && r <= y) return seg->sum;
    if (r < x || l > y) return 0;
    
    ll m = (l+r)/2;
    return query(seg->lf, l, m, x, y) + query(seg->rg, m + 1, r, x, y);
}

void update(Segment *seg, ll l, ll r, ll x, ll y, ll M) {
    if (r < x || l > y || seg->mx < M) return;
    if (l == r) {
        seg->sum %= M;
        seg->mx %= M;
        return;
    }
    
    ll m = (l+r)/2;
    update(seg->lf, l, m, x, y, M);
    update(seg->rg, m + 1, r, x, y, M);
    
    seg->sum = seg->lf->sum + seg->rg->sum;
    seg->mx = max(seg->lf->mx, seg->rg->mx);
}

int main() {
    ll n, q; cin >> n >> q;
    v.resize(n+2);
    
    for (ll i=1; i<=n; i++) cin >> v[i];
    
    root = new Segment();
    build(root, 1, n);
    
    while (q--) {
        ll x, l, r; cin >> x >> l >> r;
        
        if (x == 1) {
            ll m; cin >> m;
            update(root, 1, n, l, r, m);
        } else {
            cout << query(root, 1, n, l, r) << '\n';
        }
    }
}
