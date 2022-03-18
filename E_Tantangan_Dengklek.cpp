#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map< vector<int>, int > m;
queue< vector<int> > q;
vector<int> arr;
int n, k, ans = -1;

bool sorted(vector<int> v){
  bool res = true;
  for(int i=1;i<n;i++){
    if(v[i]<v[i-1]){
      res = false;
      break;
    }
  }
  return res;
}

int main(){
  cin >> n;
  arr = vector<int>(n);
  for(int i=0;i<n;i++) cin >> arr[i];
  cin >> k;
  q.push(arr);
  m[arr] = 0;
  while(!q.empty()){
    vector<int> cur = q.front(); q.pop();
    if(sorted(cur)){
      ans = m[cur];
      break;
    }
    for(int i=0;i<n-k+1;i++){
      vector<int> nxt = cur;
      reverse(nxt.begin()+i, nxt.begin()+i+k);
      if(!m.count(nxt)){
        m[nxt] = m[cur] + 1;
        q.push(nxt);
      }
    }
  }
  cout << ans;
}
