#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define fi first
#define se second

ll n, k, t, d, sum, cnt, total;

int main() {
    cin >> n >> k >> t >> d;
    
    ll x[n+2];
    
    priority_queue<pll> pq; // (xi, i)
    vector<vector<ll>> ans(k+2);
    vector<ll> v[k+2];
    
    for (ll i=1; i<=n; i++) cin >> x[i];
    for (ll i=1; i<=n; i++) {
        ll e; cin >> e;
        v[e].push_back(i);
    }
    
    sum = 0;
    for (ll ht=1; ht<=k; ht++) {
        for (auto planeInd : v[ht]) {
            pq.push(pll(x[planeInd] + sum, planeInd));
        }
        
        cnt = min(t, (ll) pq.size());
        ans[ht].push_back(cnt);
        
        sum += d;
        
        for (ll i=1; i<=cnt; i++)  {
            pll cur = pq.top(); pq.pop();
            ans[ht].push_back(cur.se);
            if (cur.fi >= sum)
                total += cur.fi - sum;
        }
    }
    
    cout << total << '\n';
    for (ll i=1; i<=k; i++) {
        for (ll j=0; j<=ans[i][0]; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    
}
