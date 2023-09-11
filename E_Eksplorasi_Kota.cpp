// https://tlx.toki.id/problems/schematics-2021-npc-junior-final/E/submissions/1499338

#include<iostream>
#include<vector>
using namespace std;

#define int long long
const int MAX_N = 2e5+5;

vector<int> adjlist[MAX_N];
int dep[MAX_N];
int n, m;
bool good;

void dfs(int cur, int prev) {
    for (auto nx : adjlist[cur]) {
        if (dep[nx]) {
            int res = dep[cur] - dep[nx] + 1; // odd
            if (res%2) good = 1;
            continue;
        }
        
        dep[nx] = dep[cur] + 1;
        dfs(nx, cur);
    }
}

signed main() {
    cin >> n >> m;
    
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    
    for (int i=1; i<=n; i++) {
        if (dep[i]) continue;
        
        dep[i] = 1;
        dfs(i, 0);
    }
    
    cout << (good ? "Ya" : "Tidak");
}
