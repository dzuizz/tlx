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

typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define fr front()
#define bk back()
#define pb push_back
#define pf push_front
#define ins insert
#define fi first
#define se second

#define each(a, x) for (auto& a: x)

int gcd(int a, int b);
int pow(int a, int b);

const int INF = 1e9;
const int MOD = 1e9 + 7;
vector<vector<int> > dp;
vi h, k, d;
int n, m;

int func(int cur, int val) {
    if (dp[val][cur] != -1) return dp[val][cur];
    if (cur < 0) return 0;
    int res = 0;

    if (d[cur] == 0) {
        res = func(cur - 1, val);
        if (val >= h[cur]) res = max(res, max(func(cur, val - h[cur]) + k[cur], func(cur - 1, val - h[cur]) + k[cur]));
    } else {
        res = func(cur - 1, val);
        if (val >= h[cur]) res = max(res, func(cur - 1, val - h[cur]) + k[cur]);
    }

    return dp[val][cur] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    dp.assign(m + 5, vector<int>(n + 5, -1));
    h.resize(n);
    k.resize(n);
    d.resize(n);

    for (int i = 0; i < n; i++)
        cin >> h[i] >> k[i] >> d[i];

    cout << func(n - 1, m) << '\n';
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int pow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int x = pow(a, b/2);
    if (b%2 == 0) return x*x;
    return x*x*a;
}