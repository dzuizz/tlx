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

vll a;
ll n, h, ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> h;
    
    a.resize(n, 0);
    
    REP(i, n) cin >> a[i];
    
    ll lfShift = 0, rgShift = 0;
    
    priority_queue<ll> lf; // Max-heap
    priority_queue<ll, vector<ll>, greater<ll> > rg; // Min-heap
    
    lf.push(a[0]);
    rg.push(a[0]);
    
    FOR(i, 1, n, 1) {
        lfShift -= h;
        rgShift += h;
        
        ll lfMainPoint = lf.top() + lfShift;
        ll rgMainPoint = rg.top() + rgShift;
        ll newPoint = a[i];
        
        if (newPoint < lfMainPoint) {
            ans += lfMainPoint - newPoint;
            
            lf.pop();
            rg.push(lfMainPoint - rgShift);
            
            lf.push(newPoint - lfShift);
            lf.push(newPoint - lfShift);
        } 
        
        else if (newPoint > rgMainPoint) {
            ans += newPoint - rgMainPoint;
            
            rg.pop();
            lf.push(rgMainPoint - lfShift);
            
            rg.push(newPoint - rgShift);
            rg.push(newPoint - rgShift);
        } 
        
        else {
            lf.push(newPoint - lfShift);
            rg.push(newPoint - rgShift);
        }
    }
    
    cout << ans << '\n';
}

