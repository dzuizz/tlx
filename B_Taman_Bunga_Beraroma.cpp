/*********************************HEADER**********************************

Topic    : Graph Algorithm (Shortest Path Algorithm)
Problem  : https://tlx.toki.id/courses/competitive/chapters/11/problems

**************************************************************************/

#include <iostream>
using namespace std;

#define fi first
#define se second

typedef pair< pair< int, int >, int > iii;

const int INF = 2e9;

int main() {
  int t; cin >> t;  
  while(t--) {
    int n, e; cin >> n >> e;
    
    iii edges[e+2];
    int dist[n+2];
    
    for(int i=0;i<e;i++) {
      int a, b, c; cin >> a >> b >> c;
      edges[i] = {{a, b}, c};
    }
    dist[0] = 0;
    for(int i=1;i<=n;i++) {
      dist[i] = INF;
    }
    
    bool relax;
    for(int i=0;i<n;i++) {
      relax = false;
      
      for (int l = 0 ; l < e ; l++) {
        int a = edges[l].fi.fi;
        int b = edges[l].fi.se;
        int c = edges[l].se;
        if(dist[a] == INF) continue;
        if(dist[b] > dist[a]+c) {
          dist[b] = dist[a]+c;
          relax = true;
        }
      }
    }
    if(relax) cout << "Pak Dengklek tidak mau pulang\n";
    else if(dist[n-1] == INF) cout << "Tidak ada jalan\n";
    else cout << dist[n-1] << endl;
  }
}











