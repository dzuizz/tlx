#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int n;

int main(){
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  sort(arr, arr+n);
  cout << fixed << setprecision(1) << 1.0*(arr[n/2]+arr[(n-1)/2])/2;
}