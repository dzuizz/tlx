/*********************************HEADER**********************************

Topic    : Graph Algorithm (Shortest Path Algorithm)
Problem  : https://tlx.toki.id/courses/competitive/chapters/11/problems

**************************************************************************/

#include <iostream>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair< pair< ll, ll >, ll > iii;

const ll INF = 2e9;

int main() {
  ll n, e, q; cin >> n >> e >> q;
  
  ll dis[n+2][n+2];
  
  for(ll i = 1; i <= n; i++) {
    for(ll l = 1; l <= n; l++) {
      dis[i][l] = INF;
    }
  }
  for(ll i = 1; i <= n; i++) {
    dis[i][i] = 0;
  }
  for(ll i = 1; i <= e; i++) {
    ll a, b, c; cin >> a >> b >> c;
    dis[a][b] = min(dis[a][b], c);
    dis[b][a] = min(dis[a][b], c);
  }
  for(ll i = 1; i <= n; i++) {
    for(ll l = 1; l <= n; l++) {
      for(ll j = 1; j <= n; j++) {
        if(dis[l][j] > dis[l][i] + dis[i][j]) {
          dis[l][j] = dis[l][i] + dis[i][j];
        }
      }
    }
  }
  ll ans = 0;
  ll prev, cur; cin >> prev;
  for(ll i=1;i<q;i++) {
    cin >> cur;
    ans += dis[prev][cur];
    prev = cur;
  }
  cout << ans << endl;
}

/*

// Dijkstra
Q * (N+M) * log (N+M) = 200 * (200+10000) * log (10000+200)
                      = 2e2 * 1e4 * 14
                      = 28e6
                      = 3e7 < 1e8 
                    
// Floyd-Warshall
N^3 + Q = 200^3 + 200
        = 8e6 + 200
        = 9e6 < 3e7







*/