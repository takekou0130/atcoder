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

string s,t;
int dp[2020][2020];

int main(){
  cin >> s >> t;
  rep(i, 2020) rep(j, 2020) dp[i][j] = 0;

  rep(i, s.size()+1) {
    rep(j, t.size()+1) {
      chmax(dp[i+1][j], dp[i][j]);
      chmax(dp[i][j+1], dp[i][j]);
      if(i != 0 && j != 0 && s[i-1] == t[j-1]) chmax(dp[i+1][j+1], dp[i][j]+1);
    }
  }


  int ans = 0;
  rep(j, t.size()+2) chmax(ans, dp[s.size()+1][j]);
  cout << ans << endl;
  // cout << dp[s.size()+1][t.size()+1] << endl;

}
