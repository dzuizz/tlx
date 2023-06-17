#include<algorithm>
#include<iostream>
using namespace std;

int main() {
    int t; cin >> t;
    
    for (int c=1; c<=t; c++) {
        int n, k; cin >> n >> k;
        int a[n];
        
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a, a + n);
        
        int l=0, ans=1;
        for (int r=1; r<n; r++) {
            while (a[r] - a[l] > k) l++;
            ans = max(ans, r - l + 1);
        }
        
        cout << "Case #" << c << ": " << ans << '\n';
    }
}