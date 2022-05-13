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

string s, t;
string dp[3002][3002];

int main(){
  cin >> s >> t;
  rep(i, s.size()+1) dp[i][0] = "";
  rep(j, t.size()+1) dp[0][j] = "";

  rep(i, s.size()+1) {
    rep(j, t.size()+1) {
      dp[i+1][j+1] = dp[i+1][j];
      if (dp[i+1][j+1].size() < dp[i][j+1].size()) dp[i+1][j+1] = dp[i][j+1];
      if (s[i] == t[j] && dp[i+1][j+1].size() < dp[i][j].size()+1) dp[i+1][j+1] = dp[i][j]+s[i];
    }
  }

  cout << dp[s.size()][t.size()] << endl;
}
