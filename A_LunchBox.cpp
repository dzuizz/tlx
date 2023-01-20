#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int n, m;

int main(){
    cin >> n >> m;
    int arr[m];
    for(int i=0;i<m;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+m);
    int ind = 0;
    while(ind < m && n >= arr[ind]) {
        n -= arr[ind++];
    }
    cout << ind << endl;
}
