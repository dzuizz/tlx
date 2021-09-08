#include <iostream>
using namespace std;

int main(){
    int n, x, e;
    cin >> n;
    int rank[n];
    for(int i=0;i<n;i++){
        cin >> e;
        rank[i] = e;
    }
    cin >> x;
    for(int i=0;i<n;i++){
        if(rank[i]==x){
            cout << i+1;
            break;
        }
    }
}