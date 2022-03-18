/*********************************HEADER**********************************

Jamboard : https://jamboard.google.com/d/1sJt51tfL7o2SpnsceJ_SHVXMnuV3VORSMH0kRF_QzYo/viewer?f=1

Problem : https://tlx.toki.id/courses/competitive/chapters/12/problems/B
Example : {
  array: https://ideone.com/LJJJB9 ,
  pointer: https://ideone.com/dyJ2kv
}

There are N nails on the wall. And then we put a rubber band around all nails. 
Which nails have contact with the rubber band?

N
(X1,Y1)
(X2,Y2)
(X3,Y3)
...
(Xn,Yn)

**************************************************************************/
#include<iostream>
using namespace std;

int x1, y1, x2, y2, x3, y3, x4, y4;

bool isInside(double x, double y) {
  return (x1 < x && x < x2) && (y1 < y && y < y2);
}

bool isOnFrame(double x, double y) {
  return ( (x == x1 || x == x2) && (y1 <= y && y <= y2)) || 
         ( (y == y1 || y == y2) && (x1 <= x && x <= x2));
}

// (xa,ya) == (xb,yb)
bool rec(double xa, double ya, double xb, double yb) {
  // basecases
  if (isInside(xa, ya) ^ isInside(xb, yb)) return true;
  if (isOnFrame(xa, ya) || isOnFrame(xb, yb)) return true;
  if (
    (xa < x1 && xb < x1) || 
    (xa > x2 && xb > x2) || 
    (ya < y1 && yb < y1) || 
    (ya > y2 && yb > y2) || 
    (isInside(xa, ya) && isInside(xb, yb))
    ) {
    return false;
  }
  
  // transition
  double mx = (xa+xb)/2, my = (ya+yb)/2;
  return rec(xa, ya, mx, my) || rec(mx, my, xb, yb);
}

int main() {
  int t; cin >> t;
  while(t--) {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    
    if(rec(x3, y3, x4, y4)) cout << "YA\n";
    else cout << "TIDAK\n";
  }
}