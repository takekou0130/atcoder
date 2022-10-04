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
  rep(i, 2020) rep(j, 2020) dp[i][j] = 1e8;

  rep(i, s.size()+1) dp[i][0] = i;
  rep(j, t.size()+1) dp[0][j] = j;

  rep2(i, 1, s.size()+1) {
    rep2(j, 1, t.size()+1) {
      chmin(dp[i][j], dp[i-1][j]+1);
      chmin(dp[i][j], dp[i][j-1]+1);
      chmin(dp[i][j], dp[i-1][j-1]+(s[i-1] == t[j-1] ? 0 : 1));
    }
  }

  cout << dp[s.size()][t.size()] << endl;
}
