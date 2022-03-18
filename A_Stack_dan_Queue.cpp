#include<iostream>
#include<deque>
using namespace std;

int main() {
    int n; cin >> n;
    
    deque<int> dq;
    
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        if(s == "push_back") {
        int e; cin >> e;
        dq.push_back(e);
        } else if (s == "push_front") {
        int e; cin >> e;
        dq.push_front(e);
        } else if (s == "pop_back") dq.pop_back();
        else dq.pop_front();
    }
    for(int i = 0; i < dq.size(); i++) cout << dq.at(i) << '\n';
}
