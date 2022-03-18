/*********************************HEADER**********************************

Jamboard : https://jamboard.google.com/d/1sJt51tfL7o2SpnsceJ_SHVXMnuV3VORSMH0kRF_QzYo/viewer?f=1

Problem : https://tlx.toki.id/courses/competitive/chapters/12/problems/A
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
#include<cmath>
using namespace std;

int square(int n) {return n*n;}

int main() {
  int x[2], y[2], r[2];
  for(int i : {0, 1}) cin >> x[i] >> y[i] >> r[i];
  int dist = square(x[0] - x[1]) + square(y[0] - y[1]);
  // cout << ">> " << dist << ' ' << r[0]+r[1] << endl;
  if( dist <= square(r[0] + r[1]) && square(r[0] - r[1]) <= dist ) cout << "bersentuhan\n";
  else cout << "tidak bersentuhan\n";
}
