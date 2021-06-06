#include <iostream>
using namespace std;

int main(){
    int n;
    string s, r="";
    cin >> n;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i] != r[r.length()-1]){
            r += s[i];
        }
    }
    cout << r << endl;
}