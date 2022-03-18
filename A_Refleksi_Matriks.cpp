#include <iostream>
using namespace std;
typedef long long ll;

const int N = 75;
int n;
int a[N][N], b[N][N], c[N][N];

bool identic(int a[][N], int b[][N]) {
    bool c=true;
    for(int l=0;l<n && c;l++){
        for(int j=0;j<n && c;j++){
            if(a[l][j]!=b[l][j]){
              c = false;
            }
        }
    }
    return c;
}

int main(){
    cin >> n >> n;
    for(int l=0;l<n;l++){
        for(int j=0;j<n;j++){
            cin >> a[l][j];
        }
    }
    cin >> n >> n;
    for(int l=0;l<n;l++){
        for(int j=0;j<n;j++){
            cin >> b[l][j];
        }
    }
    
    // Identical
    if(identic(a, b)){
        cout << "identik";
        return 0;
    }
    
    // Vertical
    for(int j=0;j<n;j++){
        for(int l=0;l<n;l++){
            c[l][j] = b[l][n-j-1];
        }
    }
    if(identic(a, c)){
        cout << "vertikal";
        return 0;
    }
    
    // Horizontal
    for(int l=0;l<n;l++){
        for(int j=0;j<n;j++){
            c[l][j] = b[n-l-1][j];
        }
    }
    if(identic(a, c)){
      cout << "horisontal";
      return 0;
    }
    
    // Right-Bottom Diagonal
    for(int l=0;l<n;l++){
        for(int j=0;j<n;j++){
            c[l][j] = b[j][l];
        }
    }
    if(identic(a, c)){
      cout << "diagonal kanan bawah";
      return 0;
    }
    
    // Left-Bottom Diagonal
    for(int l=0;l<n;l++){
        for(int j=0;j<n;j++){
            c[l][j] = b[n-j-1][n-l-1];
        }
    }
    if(identic(a, c)){
      cout << "diagonal kiri bawah";
      return 0;
    }
    
    // Nothing
    cout << "tidak identik";
}