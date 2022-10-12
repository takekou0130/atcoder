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

int n;
string s;
vector<char> v;
vector<char> fu;

int main(){
  cin >> n;
  cin >> s;
  rep(i, s.size()) {
    if(s[i] == '(') v.push_back(')');
    if(s[i] == ')' && v[v.size()-1] == ')') {
      v.pop_back();
    }
    else if(s[i] == ')' && v.size() == 0) {
      fu.push_back('(');
    }
  }
  string ans = "";
  for(auto f: fu) ans += f;
  ans += s;
  for(auto f: v) ans += f;
  cout << ans << endl;

}
