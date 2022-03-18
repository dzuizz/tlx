/*********************************HEADER**********************************

Topic    : Data Structure
Problem  : https://vjudge.net/contest/455106
https://tlx.toki.id/courses/competitive/chapters/08/problems/D

**************************************************************************/

/*
Data Structure:
- Vector -> an array (but dynamic)
- Queue -> FIFO (only access the first element)
- Priority_queue -> Priority (only access the priority) 
- Stack -> LIFO (only access the last element)
- Set -> Non-duplicating
- Multiset -> Duplicating
*/

#include<iostream>
#include<stack>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

const int INF = 1e9;

int main() {
  int n; cin >> n;
  
  int heights[n];
  stack<ii> s; // Index, Height
  long long ans = 0;
  
  for(int i = 0; i < n; i++) cin >> heights[i];
  s.push(ii(-1, INF));
  for(int i = 0; i < n; i++) {
    while(heights[i] >= s.top().se) s.pop();
    ans += i - s.top().fi;
    s.push(ii(i, heights[i]));
  }
  
  cout << ans << endl;
}