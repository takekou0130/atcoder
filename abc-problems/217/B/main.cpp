#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int main(){
  set<string> s = { "ABC", "ARC", "AGC", "AHC" };
  rep(i, 3){
    string in;
    cin >> in;
    s.erase(in);
  }
  cout << *s.begin() << endl;
}
