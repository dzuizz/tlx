#include <iostream>
#include <map>
using namespace std;

int n, q;
string name, phone;
map<string, string> m;

int main(){
  cin >> n >> q;
  for(int i=0;i<n;i++){
    cin >> name >> phone;
    m[name]= phone;
  }
  for(int i=0;i<q;i++){
    cin >> name;
    if (m.count(name)) cout << m[name] << endl;
    else cout << "NIHIL\n";
  }
}
