#include<iostream>
using namespace std;

int main() {
    int n; cin >> n;

    int ans=0;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        ans = max(ans, a*b);
    }

    cout << ans << '\n';
}