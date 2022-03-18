#include <iostream>
using namespace std;
typedef long long ll;

int n;

void ans(int n){
    if(n==0){
        return;
    }
    ans(n-1);
    for(int i=0;i<n;i++){
        cout << "*";
    }
    cout << "\n";
    ans(n-1);
}

int main(){
    cin >> n;
    ans(n);
}