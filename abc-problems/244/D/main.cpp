#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

vector<char> s(3);
vector<char> t(3);

int main(){
  rep(i, 3){
    cin >> s.at(i);
  }
  rep(i, 3) cin >> t.at(i);

  if(s[0] == t[0] && s[1] == t[1] && s[2] == t[2]){
    cout << "Yes" << endl;
    return 0;
  }

if(s[0] == t[0] && s[1] != t[1]){
    cout << "No" << endl;
    return 0;
  }

  if(s[1] == t[1] && s[2] != t[2]){
    cout << "No" << endl;
    return 0;
  }

  if(s[1] != t[1] && s[2] == t[2]){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
}
