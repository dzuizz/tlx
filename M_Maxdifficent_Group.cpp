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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll n; cin >> n;
    ll a[n], prefMaxSum[n], prefMinSum[n], suffMaxSum[n], suffMinSum[n];
    
    REP(i, n) cin >> a[i];
    
    ll sum = 0, res = a[0];
    REP(i, n) {
        sum = max(a[i], sum + a[i]);
        res = max(res, sum);
        prefMaxSum[i] = res;
    }
    
    sum = 0, res = a[0];
    REP(i, n) {
        sum = min(a[i], sum + a[i]);
        res = min(res, sum);
        prefMinSum[i] = res;
    }
    
    sum = 0, res = a[n - 1];
    RREP(i, n) {
        sum = max(a[i], sum + a[i]);
        res = max(res, sum);
        suffMaxSum[i] = res;
    }
    
    sum = 0, res = a[n - 1];
    RREP(i, n) {
        sum = min(a[i], sum + a[i]);
        res = min(res, sum);
        suffMinSum[i] = res;
    }
    
    ll ans = 0;
    REP(i, n - 1) {
        ans = max(ans, prefMaxSum[i] - suffMinSum[i + 1]);
        ans = max(ans, suffMaxSum[i + 1] - prefMinSum[i]);
    }
    
    cout << ans << '\n';
}
