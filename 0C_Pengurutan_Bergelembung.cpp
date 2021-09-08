#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s=="PAS"){
        cout << "var data:array[1..10000] of longint;\n";
        cout << "    n,i,j,temp:longint;\n";
        cout << "begin\n";
        cout << "  readln(n);\n";
        cout << "  for i:=1 to n do readln(data[i]);\n";
        cout << "  for i:=1 to n-1 do\n";
        cout << "    for j:=i+1 to n do\n";
        cout << "      if (data[i]>data[j]) then\n";
        cout << "      begin\n";
        cout << "        temp:=data[i];\n";
        cout << "        data[i]:=data[j];\n";
        cout << "        data[j]:=temp;\n";
        cout << "      end;\n";
        cout << "  for i:=1 to n do writeln(data[i]);\n";
        cout << "end.\n";
    }else{
        cout << "int data[10001];\n";
        cout << "int n,i,j,temp;\n";
        cout << "int main(){\n";
        cout << "  scanf(\"%d\",&n);\n";
        cout << "  for (i=1;i<=n;i++) scanf(\"%d\",data[i]);\n";
        cout << "  for (i=1;i<=n-1;i++)\n";
        cout << "    for (j=i+1;j<=n;j++)\n";
        cout << "      if (data[i]>data[j]){\n";
        cout << "        temp=data[i];\n";
        cout << "        data[i]=data[j];\n";
        cout << "        data[j]=temp;\n";
        cout << "      }\n";
        cout << "  for (i=1;i<=n;i++) printf(\"%d\\n\",data[i]);\n";
        cout << "  return 0;\n";
        cout << "}\n";
    }
}