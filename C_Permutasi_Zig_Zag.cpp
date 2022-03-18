#include <iostream>
using namespace std;
typedef long long ll;

int n;
string res="";
bool available[10]={true, true, true, true, true, true, true, true, true, true};

void ans(int a){
    if(a==n){
        bool zigzag=true, prevaGreaterb=true;
        if(res[0]<res[1]) prevaGreaterb=false;
        for(int i=2;i<n;i++){
            if(res[i]>res[i-1] && !prevaGreaterb){
                zigzag = false;
                break;
            }
            if(res[i]<res[i-1] && prevaGreaterb){
                zigzag = false;
                break;
            }
            prevaGreaterb = !prevaGreaterb;
        }
        if(zigzag){
            cout << res << endl;
        }
        return;
    }

    for(int ind=1;ind<=n;ind++){
        if(available[ind]){
            available[ind] = false;
            res += char(ind+'0');
            ans(a+1);
            available[ind] = true;
            res.pop_back();
        }
    }
}

int main(){
    cin >> n;
    ans(0);
}