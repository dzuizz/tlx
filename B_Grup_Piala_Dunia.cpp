#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int t, n, table[5][5], inp[5], arr[3]={0, 1, 3};
string overall = "NO";

void fill(int l, int j){
  if(l>=n){
    bool correct = true;
    for(int i=0;i<n && correct;i++){
      int sum = 0;
      for(int l=0;l<n;l++){
        sum += table[i][l];
      }
      if(sum!=inp[i]) correct = false;
    }
    if(correct) overall = "YES";
    return;
  }
  if(j>=l) {
    fill(l+1,0);
    return;
  }
  for(int i=0;i<3;i++){
    int ch = arr[i];
    table[l][j] = ch;
    if(ch==0) table[j][l] = 3;
    else if(ch==1) table[j][l] = 1;
    else table[j][l] = 0;
    fill(l, j+1);
  }
}

int main(){
  cin >> t;
  while(t--){
    overall = "NO";
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> inp[i];
    }
    fill(1, 0);
    cout << overall << endl;
  }
}

