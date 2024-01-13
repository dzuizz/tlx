#include "shoes.h"
#include <bits/stdc++.h>
using namespace std;

int ft[200005];
map<int, priority_queue<int, vector<int>, greater<int> > > ipq;

void add(int x, int v) {
    for (; x<=200000; x += (x & -x)) ft[x] += v;
}

int sum(int x) {
    int ret = 0;
    for (; x>0; x -= (x & -x)) ret += ft[x];
    return ret;
}

int rsq(int x, int y) {
    return sum(y) - sum(x-1);
}

long long count_swaps(vector<int> s) {
    int n = s.size()/2;
    
    for (int i=0; i<n*2; i++) {
        ipq[s[i]].push(i);
    }
    
    long long ans = 0;
    for (int i=0; i<n*2; i++) {
        if (rsq(i, i)) continue;
        
        int x = ipq[-s[i]].top();
        ipq[s[i]].pop();
        ipq[-s[i]].pop();
        add(x, 1);
        
        ans += x - i - 1 - rsq(i+1, x-1) + (s[i] > 0);
    }
    
    return ans;
}