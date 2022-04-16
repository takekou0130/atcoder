#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

string s, t;
char S[101];
char T[101];

int main(){
  cin >> s >> t;
  int size = (int)s.size();
  rep(i, size){
    S[i] = s[i];
  }
  rep(i, size){
    T[i] = t[i];
  }
  rep(i, size-1){
    if(S[i] == T[i]) continue;
    swap(S[i], S[i+1]);
    bool flag = true;
    rep(i, size){
      if(S[i] == T[i]) continue;
      flag = false;
    }
    if(flag) break;
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
