#include <iostream>
using namespace std;

int n, m, colour, bigCluster, total;
int graph[25][25], xs[4]={1, -1, 0,  0},
                 ys[4]={0,  0, 1, -1};

void find(int x, int y){
  total++;
  graph[x][y] = 0;
  for(int i=0;i<4;i++){
    int newx = x+xs[i], newy = y+ys[i];
    if( (newx>=0 && newx<n) && (newy>=0 && newy<m) && graph[newx][newy] == colour){
      find(newx, newy);
    }
  }
}

int main(){
  cin >> n >> m;
  for(int l=0;l<n;l++){
    for(int j=0;j<m;j++){
      cin >> graph[l][j];
    }
  }
  for(int l=0;l<n;l++){
    for(int j=0;j<m;j++){
      colour = graph[l][j];
      if(colour>0){
        total = 0;
        find(l, j);
        if(total>bigCluster) bigCluster = total;
      }
    }
  }
  cout << bigCluster*(bigCluster-1);
}