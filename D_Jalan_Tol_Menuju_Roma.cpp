#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fi first
#define se second

const int INF = 1e9;
int n, l, t, s, r, a, b, ans=INF;

int main(){
  cin >> n >> l >> t >> s >> r;
  queue< pair<int, int> > q;
  vector<int> regular[n];
  vector<int> highway[n];
  int dist[n][2];
  s--, r--;
  
  for(int i=0;i<l;i++){
    cin >> a >> b;
    regular[--a].push_back(--b);
    regular[b].push_back(a);
  }
  for(int i=0;i<t;i++){
    cin >> a >> b;
    highway[--a].push_back(--b);
    highway[b].push_back(a);
  }
  for(int i=0;i<n;i++) {
    for (int j = 0; j < 2; j++) {
      dist[i][j] = INF;
    }
  }
  q.push({s, 0});
  dist[s][0] = 0;
  while(!q.empty()){
    pair<int,int> cur = q.front(); q.pop();
    // cout << cur.fi << ' ' << cur.se << " -> " << dist[cur.fi][cur.se] << '\n';
    for(int neighbour : regular[cur.fi]){
      if(dist[neighbour][cur.se] == INF){
        dist[neighbour][cur.se] = dist[cur.fi][cur.se] + 1;
        q.push({neighbour, cur.se});
      }
    }
    if(cur.se == 0){
      for(int neighbour : highway[cur.fi]){
        if(dist[neighbour][1] == INF){
          dist[neighbour][1] = dist[cur.fi][cur.se] + 1;
          q.push({neighbour, 1});
        }
      }
    }
  }
  cout << min(dist[r][0], dist[r][1]);
}







