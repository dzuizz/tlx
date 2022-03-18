#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s;

int main(){
  cin >> n;
  string arr[n];
  for(int i=0;i<n;i++){
    cin >> s;
    arr[i] = s;
    sort(arr, arr+i+1);
    for(int ii=0;ii<n;ii++){
      if(arr[ii]==s){
        cout << ii+1 << endl;
        break;
      }
    }
  }
}