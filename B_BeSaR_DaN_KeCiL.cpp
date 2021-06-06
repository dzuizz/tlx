#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int _=0;_<t;_++){
        bool c=true;
        string s, r="";
        cin >> s;
        for(int i=0;i<s.length();i++){
            if (c==true){
                r += s[i]-32;
            } else {
                r += s[i];
            }
            c = !c;
        }
        cout << r << endl;
    }
}