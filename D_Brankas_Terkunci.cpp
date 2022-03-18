#include <iostream>
using namespace std;
typedef long long ll;

int n, k;
int arr[10];

void ans(int a){
    if(a==k){
        for(int i=0;i<k;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=arr[a-1]+1;i<=n;i++){
        arr[a] = i;
        ans(a+1);
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<k;i++) arr[i] = i+1;
    ans(0);
}