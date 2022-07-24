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

ll n,m;
ll x[5005];
ll bonus[5005];
ll dp[5005][5005];

int main(){
  cin >> n >> m;
  rep(i,n) cin >> x[i];
  rep(i,5005){
    bonus[i] = 0;
    rep(j, 5005){
      dp[i][j] = 0;
    }
  }

  rep(i, m){
    ll c, y;
    cin >> c >> y;
    bonus[c] = y;
  }

  dp[0][1] = x[0]+bonus[1];

  rep(i, n){
    rep(point, min(i+2,(int)n+1)){
      chmax(dp[i+1][0],dp[i][point]);
      chmax(dp[i+1][point+1], dp[i][point]+x[i+1]+bonus[point+1]);
    }
  }

  ll ans = 0;
  rep(i, n+1){
    chmax(ans, dp[n-1][i]);
  }
  cout << ans << endl;
}
