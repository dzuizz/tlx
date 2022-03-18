#include <iostream>
using namespace std;

const int INF = 1e6+1;
const int N = 1e5;
int n, q, x, y;
int duck[N+1];

int FindLeft(int l, int r){
  if (l > r) return INF;
  int mid = (l+r)/2, ret = mid;
  if(duck[mid]<=x) return FindLeft(mid+1, r);
  ret = min(ret,FindLeft(l, mid-1));
  return ret;
}

// int cnt;

// int FindLeft(int l, int r) {
//   if (l > r) return n+1;
//   int mid = (l+r)/2;
//   if (duck[mid] > x) return min(mid,FindLeft(l,mid-1));
//   return FindLeft(mid+1,r);
// }

int FindRight(int l, int r){
  if (l > r) return -1;
  int mid = (l+r)/2, ret = mid;
  if(duck[mid]>y) return FindRight(l, mid-1);
  ret = max(ret,FindRight(mid+1, r));
  return ret;
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++) cin >> duck[i];
  cin >> q;
  while(q--){
    cin >> x >> y;
    cout << max(0,FindRight(0,n-1)-FindLeft(0,n-1)+1) << endl;
  }
}