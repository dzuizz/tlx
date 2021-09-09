#include <stdio.h>

int main(){
    long long t, p;
    long long arr[3];
    scanf("%lld", &t);
    for(int i=0;i<t;i++) {
        long long arr[3] = {0, 0, 0};
        p=1;
        scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);
        for(int a=0;a<3;a++){
            p *= arr[a];
            p %= 1000000007;
        }
        printf("%lld\n", (p-1)%1000000007);
    }
}