#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    for(int i=1;i<=x;i++){
        int t, a=0, b=0, c=0;
        cin >> t;
        for(int ii=0;ii<t;ii++){
            string s;
            cin >> s;
            if(s.length()==4){
                a += 1;
            } else if(s.length()==5){
                b += 1;
            } else if(s.length()==6){
                c += 1;
            }
        }
        cout << "Case #" << i << ": " << a << " " << b << " " << c << endl;
    }
}
