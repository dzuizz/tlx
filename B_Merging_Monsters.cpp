#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, big=0;
    cin >> n >> m;
    ll arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n-m;i++){
        ll c=0;
        for(int a=i;a<i+m+1;a++){
            c += arr[a];
        }
        if(c>big) big = c;
    }
    cout << big << endl;
}