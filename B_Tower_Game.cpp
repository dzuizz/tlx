#include <iostream>
using namespace std;

int main(){
    bool c = true;
    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int a=0;a<m;a++){
            if (c==true){
                cout << "W";
            } else {
                cout << "B";
            }
            c = !c;
        }
        c = true;
        cout << endl;
    }

}