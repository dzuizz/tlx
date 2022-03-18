#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, x, sum=0, ind;
double ans=0;

int main(){
  cin >> n >> x;
  ind = n-1;
  int a[n], b[n];
  pair<double, int> arr[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
  }
  for(int i=0;i<n;i++){
    arr[i].first = 1.0*b[i]/a[i];
    arr[i].second = a[i];
  }
  sort(arr, arr+n);
  while(sum<x && ind>=0){
    // pair<int, int> p = arr[ind];
    int qty = min(x-sum,arr[ind].second);
    sum += qty;
    ans += qty*arr[ind].first;
    ind--;
  }
  cout << fixed << setprecision(5) << ans;
}

/*
5 5
3 2 4 1 6
9 5 4 4 3

Type   Weight   Total_Price   Price_Per_KG
 4       1           4             4
 1       3           9             3
 2       2           5             2.5
 3       4           4             1
 5       6           3             0.5
*/