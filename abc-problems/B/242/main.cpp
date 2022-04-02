#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

string s;
vector<char> S;

int main(){
  cin >> s;
  rep(i, (int)s.size()){
    S.push_back(s[i]);
  }
  sort(S.begin(), S.end());
  for(auto out: S) cout << out;
  cout << endl;
}
