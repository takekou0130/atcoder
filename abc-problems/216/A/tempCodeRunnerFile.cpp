#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define endl "\n"
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b


int main(){
  string s;
  int x,y;
  cin >> s;
  string tmp = "";
  rep(i, s.size()){
    if(s[i] == '.'){
      y = s[i+1] - '0';
    } else {
      tmp += s[i];
    }
  }
  cout << tmp;
  if(0 <= y && y <= 2) cout << '-' << endl;
  else if (y <= 6) cout << endl;
  else cout << '+' << endl;
}
