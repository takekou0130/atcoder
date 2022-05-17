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

int n, m;
ll d[1010];
ll c[1010];
ll dp[1010][1010];
ll inf = 1e18;

int main(){
  cin >> n >> m;
  rep(i, n) cin >> d[i];
  rep(i, m) cin >> c[i];

  rep(i, 1010) rep(j, 1010) dp[i][j] = inf;
  dp[0][0] = 0;

  rep(i, n){
    rep(j, m){
      if(dp[i][j] == inf) continue;

      // 待機する
      chmin(dp[i][j+1], dp[i][j]);

      // 移動する
      chmin(dp[i+1][j+1], dp[i][j]+d[i]*c[j]);
    }
  }

  ll ans = inf;
  rep(j, m+1){
    chmin(ans, dp[n][j]);
  }
  cout << ans << endl;
}
