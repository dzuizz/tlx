#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

#define int long long
#define fi first
#define se second
typedef pair<int, int> ii;

const int MAX_N = 52;

vector<vector<vector<int>>> grid;
int d, h, l;

int getMaxIn2D(vector<vector<int>> &v) {
    int a[l]; memset(a, 0, sizeof(a));
    int res = 0;
    
    for (int i=0; i<h; i++) {
        stack<ii> st;
        
        for (int j=0; j<l; j++) {
            if (v[i][j] == 1) a[j]++;
            else a[j] = 0;
            
            int low=j;
            while (!st.empty() && st.top().fi > a[j]) {
                res = max(res, st.top().fi*(j-st.top().se));
                low = min(low, st.top().se);
                st.pop();
            }
            st.push(make_pair(a[j], low));
        }
        
        while (!st.empty()) {
            res = max(res, st.top().fi*(l-st.top().se));
            st.pop();
        }
    }
    
    return res;
}

signed main() {
    cin >> d >> h >> l;
    
    grid = vector<vector<vector<int>>>(d, 
        vector<vector<int>>(h,
            vector<int>(l)
        )
    );
    
    for (int i=0; i<d; i++) {
        for (int j=0; j<h; j++) {
            for (int k=0; k<l; k++) {
                cin >> grid[i][j][k];
            }
        }
    }
    
    int ans=0;
    for (int i=0; i<d; i++) {
        vector<vector<int>> v(h, vector<int>(l, 1));
        
        for (int j=i; j<d; j++) {
            for (int p=0; p<h; p++) {
                for (int q=0; q<l; q++) {
                    v[p][q] = min(v[p][q], grid[j][p][q]);
                }
            }
            
            ans = max(ans, getMaxIn2D(v) * (j-i+1));
        }
    }
    
    cout << ans << '\n';
}