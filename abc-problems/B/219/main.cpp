#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

string a,b,c;
string n;

int main(){
  cin >> a >> b >> c >> n;
  rep(i, (int)n.size()){
    if(n[i] == '1') cout << a;
    if(n[i] == '2') cout << b;
    if(n[i] == '3') cout << c;
  }
  cout << endl;
}
