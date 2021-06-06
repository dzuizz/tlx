#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(count(s.begin(), s.end(), 'O') == 1){
        cout << "Ya\n";
    } else {
        cout << "Tidak\n";
    }
}