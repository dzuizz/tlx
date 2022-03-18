#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll inp;
ll arr[55];

// Top Down Method
/*

ll func(ll n){
    ll sum = 0;
    if(arr[n] != -1) return arr[n];
    for(ll i=0;i<n/2;i++){
        sum += func(i*2) * func(n - (i+1)*2);
    }
    return arr[n] = sum;
}
*/

int main(){
    cin >> inp;
    memset(arr, -1, sizeof(arr));
    arr[0] = 1, arr[1] = 1, arr[2] = 1;
    /*
    if(inp%2==0) cout << func(inp);
    else cout << 1;
    */
   
   // Bottom Up Method
   for(int n=4;n<=inp;n++){
       ll sum=0;
       for(ll i=0;i<n/2;i++){
            sum += arr[i*2] * arr[n - (i+1)*2];
        }
        arr[n] = sum;
   }
   cout << arr[inp];
}