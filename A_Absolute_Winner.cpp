#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr+3);
    if( (arr[0]+arr[1])/3*4 == arr[2] ) cout << "YA\n";
    else cout << "TIDAK\n";
}