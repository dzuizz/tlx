#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int t, n, a, b, k;
    cin >> t;
    for(int c=1;c<=t;c++){
        cin >> n >> a >> b >> k;
        printf("Kasus #%d: %d\n", c, n + (b-a) * k);
    }
}