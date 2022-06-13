#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define fi first
#define se second

vector<iii> dsu; // (leader's index, no. of lions, no. of tigers)
int n;

int find(int n) {
  if (dsu[n].fi == n) return n;
  return dsu[n].fi = find(dsu[n].fi);
}

void merge(int a, int b) { // a -> b
  a = find(a); b = find(b);
  if (a == b) return;
  
  dsu[b].se.fi += dsu[a].se.fi;
  dsu[b].se.se += dsu[a].se.se;
  dsu[a].fi = b;
}

int main() {
  cin >> n;
  
  int v[n+2], e[n+2];

  dsu = vector<iii>(n+102);
  for (int i = n+1; i <= n+100; i++) dsu[i] = iii(i, ii(0, 0));
  
  dsu[0] = iii(0, ii(0, 0));
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    
    dsu[i] = iii(i, ii(0, 0));
    if (v[i] == 0) dsu[i].se.se = 1; // Tiger
    else dsu[i].se.fi = 1; // Lion
  }
  for (int i = 1; i <= n; i++) cin >> e[i];
  
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= e[i]; j++) {
      if (e[i] % j > 0) continue;
      merge(i, n+j);
    }
  }
  
  set<int> s;
  for (int i = 1; i <= n; i++) s.insert(find(i));
  
  int ans = 0;
  for (auto leader : s) {
    ans += min(dsu[leader].se.fi, dsu[leader].se.se);
  }
  
  cout << ans << endl;
}
