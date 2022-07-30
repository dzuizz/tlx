#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

int main() {
    ll n, a, b; cin >> n >> a >> b;

    ll g = gcd(a, b);
    ll mul = a * b / g;

    cout << mul / a + mul / b << '\n';
}