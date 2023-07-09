#include<iostream>
#include<stack>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int n; cin >> n;
    ii a[n];

    for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n, greater<ii>());

    stack<ii> st;

    for (int i=0; i<n; i++) {
        if (st.empty() || !(a[i].first <= st.top().first && a[i].second <= st.top().second)) st.push(a[i]);
    }

    cout << st.size() << '\n';
}