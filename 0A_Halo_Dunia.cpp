#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main(){
    locale loc;
    char s[11];
    string h = "halo dunia";
    int n=0;
    cin.getline(s, 11);
    for (int b = 0; b < 10; b++){
        s[b] = tolower(s[b], loc);
    }
    for (int i = 0; i < 10; i++){
        if (s[i] == h[i]){
            n++;
        }
    }
    cout << n << endl;
}