#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int t, c, mark;
    cin >> t;
    for(int i=1;i<=t;i++){
        int retest = 0;
        cin >> c;
        for(int j=0;j<c;j++){
            cin >> mark;
            if(mark<60){
                retest++;
            }
        }
        printf("Case #%d: %d\n", i, retest);
    }
}