#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n;
int arr[1005];

int func(int n){
    int sum=0, newTotal = n/2 + n/3 + n/4, lis[3] = {n/2, n/3, n/4};
    for(int i : lis){
        if(!i) continue;
        if(arr[i]==-1) sum += func(i);
        else sum += arr[i];
    }
    return arr[n] = max(sum, n);
}

int main(){
    cin >> n;
    memset(arr, -1, sizeof(arr));
    cout << func(n) << endl;
}