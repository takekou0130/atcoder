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
  string s,t;
  cin >> s >> t;
  if(t.size() < s.size() || t[0] != s[0] || t[1] != s[1]){
    cout << "No" << endl;
    return 0;
  }

  int idx_s = 0;
  int idx_t = 0;
  while(idx_s < s.size() || idx_t < t.size()){
    if(t[idx_t] == s[idx_s]){
      idx_t++;
      idx_s++;
    } else {
      if(t[idx_t] == s[idx_s-1] && t[idx_t] == s[idx_s-2]){
        idx_t++;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  if(idx_s == s.size() && idx_t == t.size()) cout << "Yes" << endl;
  else cout << "No" << endl;
}
