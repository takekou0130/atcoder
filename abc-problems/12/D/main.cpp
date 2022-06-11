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
ll dp[303][303];
ll inf = 1e18;

int main(){
  cin >> n >> m;
  rep(i,303) rep(j, 303) dp[i][j] = inf;
  rep(i, n) dp[i][i] = 0;

  rep(i,m){
    int a,b;
    ll t;
    cin >> a >> b >> t;
    a--;
    b--;
    chmin(dp[a][b], t);
    chmin(dp[b][a], t);
  }

  rep(k, n){
    rep(i, n){
      rep(j, n){
        chmin(dp[i][j], dp[i][k]+dp[k][j]);
      }
    }
  }

  ll ans = inf;
  rep(i, n){
    ll sum = 0;
    rep(j, n) chmax(sum, dp[i][j]);
    chmin(ans, sum);
  }

  cout << ans << endl;
}
