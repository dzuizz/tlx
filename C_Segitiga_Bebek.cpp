/*********************************HEADER**********************************

Jamboard : https://jamboard.google.com/d/1sJt51tfL7o2SpnsceJ_SHVXMnuV3VORSMH0kRF_QzYo/viewer?f=1

Problem : https://tlx.toki.id/courses/competitive/chapters/12/problems/C
Example : {
  array: https://ideone.com/LJJJB9 ,
  pointer: https://ideone.com/dyJ2kv
}

There are N nails on the wall. And then we put a rubber band around all nails. 
Which nails have contact with the rubber band?

N
(X1,Y1)
(X2,Y2)
(X3,Y3)
...
(Xn,Yn)

**************************************************************************/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<math.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

const int INF = 1e9;
const double EPS = 1e-3;

int main() {
  int n; cin >> n;
  
  ii a[n];
  double ans = INF;
  
  for(int i = 0; i < n; i++) {
    cin >> a[i].fi >> a[i].se;
    // cout << ">> " << a[i].fi << " " << a[i].se << "\n";
  }
  // sort(a, a+n);
  bool same = false;
  for(int i = 0; i < n-2; i++) {
    for(int l = i + 1; l < n-1; l++) {
      for(int j = l + 1; j < n; j++) {
        int lhs = 0, rhs = 0;
        int v[3] = {i,l,j};
        for(int k : {0, 1, 2}) {
          lhs += a[v[k]].fi * a[v[(k+1)%3]].se;
          rhs += a[v[k]].se * a[v[(k+1)%3]].fi;
        }
        // cout << i << ' ' << l << ' ' << j << " -> " << (double)abs(lhs-rhs)/2 << '\n';
        double area = (double) abs(lhs - rhs) / 2;
        if (fabs(area-0) <= EPS) continue;
        // if (area <= 0) continue;
        if (fabs(ans-area) <= EPS) {
          same = true;
        }
        else if (ans > area) {
          ans = min(ans, area);   
          same = false;
        }
      }
    }
  }
  // cout << ">> " << lhs << " " << rhs << endl;
  if(fabs(ans-INF) <= EPS || same) cout << "-1.00\n";
  else cout << setprecision(2) << fixed << ans << endl;
}

// int x;
// int cnt = 0;
// while (x > 0) x /= 10, cnt++;

// cnt == to_string(x).length()











