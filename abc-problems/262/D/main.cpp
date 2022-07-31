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
ll a[101];
ll wari[101];
ll dp[101][101][101];
ll mod = 998244353LL;

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  ll ans = 0;
  for(ll total = 1; total <= n; total++){
    rep(i, n) wari[i] = a[i] % total;
    rep(i, 101) rep(j, 101) rep(k, 101) dp[i][j][k] = 0;

    // とる
    dp[0][wari[0]][1]++;
    // とらない
    dp[0][0][0]++;
    rep(i, n) rep(j, total) rep(k, total+1) {
      if(dp[i][j][k] == 0) continue;
      // とる
      dp[i+1][(j + wari[i+1])%total][k+1] += dp[i][j][k];
      dp[i+1][(j + wari[i+1])%total][k+1] %= mod;
      // とらない
      dp[i+1][j][k] += dp[i][j][k];
      dp[i+1][j][k] %= mod;
    }

    // ans更新
    ans += dp[n-1][0][total];
    ans %= mod;
  }

  cout << ans << endl;
}
