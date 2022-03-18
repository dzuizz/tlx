/*********************************HEADER**********************************

Topic    : Graph Algorithm (Shortest Path Algorithm)
Problem  : https://tlx.toki.id/courses/competitive/chapters/11/problems

**************************************************************************/

#include <functional>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fi first
#define se second

typedef pair<int,int> ii;

const int INF = 1e7;
int n, e, start, finish, a, b, c;

int main(){
  cin >> n >> e >> start >> finish;
  
  vector<ii> adj[n+2];
  int dist[n+2];
  
  for(int i=0;i<e;i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  
  for(int i=0;i<=n;i++) {
    dist[i] = INF;
  }
  dist[start] = 0;
  priority_queue<ii> pq;
  pq.push({-0, start});
  
  while(!pq.empty()) {
    ii cur = pq.top(); pq.pop();
    if(dist[ cur.se ] != -cur.fi) continue;
    for(ii nxt : adj[cur.se]) {
      int nextDist = -cur.fi + nxt.se;
      if( nextDist < dist[nxt.fi] ) {
        dist[nxt.fi] = nextDist;
        pq.push({-nextDist, nxt.fi});
      }
    }
  }
  cout << dist[finish] << endl;
}