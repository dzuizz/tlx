#include <iostream>
#include <cstdint>
#include <cstring>
using namespace std;

int n, m, bigCluster, total, ansx, ansy;
char graph[25][25], colour;
int xs[4]={1, -1, 0,  0},
    ys[4]={0,  0, 1, -1}, visited[25][25];
    
bool valid(int newx, int newy) {
  return (newx>=0 && newx<n) && (newy>=0 && newy<m);
}

void find(int x, int y){
  total++;
  visited[x][y] = 1;
  for(int i=0;i<4;i++){
    int newx = x+xs[i], newy = y+ys[i];
    if( valid(newx,newy) && graph[newx][newy] == colour && !visited[newx][newy] ){
      find(newx, newy);
    }
  }
}

void fall(int l, int j){
  swap(visited[l][j], visited[l+1][j]);
  swap(graph[l][j], graph[l+1][j]);
  graph[l][j] = '.';
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
      if(!visited[l][j]){
        total = 0;
        find(l, j);
        if(total>bigCluster){
          bigCluster = total;
          ansx = l, ansy = j;
        }
      }
    }
  }
  
  colour = graph[ansx][ansy];
  memset(visited, 0, sizeof(visited));
  find(ansx, ansy);
    
  for(int l=n-1;l>=0;l--){
    for(int j=0;j<m;j++){
      if(visited[l][j]) {
        graph[l][j] = '.';
        continue;
      }
      int itr = l;
      while(itr+1 < n && visited[itr+1][j]) {
        fall(itr, j);
        itr++;
      }
    }
  }
  
  for(int l=0;l<n;l++){
    for(int j=0;j<m;j++){
      cout << graph[l][j] << " ";
    }
    cout << endl;
  }
}
