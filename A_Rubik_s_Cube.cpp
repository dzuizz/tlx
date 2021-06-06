#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int c=0;c<n;c++){
        int x;
        cin >> x;
        cout << x*x*x-(x-2)*(x-2)*(x-2) << endl;
    }
}