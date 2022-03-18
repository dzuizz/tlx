#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const int INF = 1e5;
int types, m;
int input[505], arr[INF];

int dp(int n){
    int res = INF;
    if(n<=0) return 0;
    if(arr[n]!=-1) return arr[n];
    for(int i=0;i<types;i++){
        int coin = input[i];
        if(n >= coin){
            res = min(res, dp(n-coin) + 1);
        }
    }
    return arr[n] = res;
}

int main(){
    cin >> types;
    memset(arr, -1, sizeof(arr));
    for(int i=0;i<types;i++){
        cin >> input[i];
    }
    cin >> m;
    cout << dp(m);
}