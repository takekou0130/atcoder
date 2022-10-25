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

ll n;
ll dp[3030][3030];
ll mod = 998244353;
ll a[3030],b[3030];

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  rep(i, 3030) rep(j, 3030) dp[i][j] = 0;

  rep2(i, a[0], b[0]+1){
    dp[0][i] = 1LL;
  }

  rep2(i, 1, n){
    rep(j, b[i]+1){
      if(j != 0) dp[i][j] += dp[i][j-1];
      dp[i][j] %= mod;
      dp[i][j] += dp[i-1][j];
      dp[i][j] %= mod;
    }

    rep(j, a[i]){
      dp[i][j] = 0;
    }
  }

  ll ans = 0;
  rep2(j, a[n-1], b[n-1]+1) {
    ans += dp[n-1][j];
    ans %= mod;
  }

  cout << ans << endl;
}
