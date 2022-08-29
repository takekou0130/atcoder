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
ll dp[101010][5];
P bonus[101010];

int main(){
  cin >> n;
  rep(i, 101009) bonus[i] = {5, 0};
  ll max_t = 0;
  rep(i, n){
    ll t,x,a;
    cin >> t >> x >> a;
    bonus[t] = {x, a};
    chmax(max_t, t);
  }
  rep(i, 101010) rep(j, 5) dp[i][j] = -1;
  dp[0][0] = 0;
  rep(i, max_t){
    rep(j, 5){
      if(dp[i][j] == -1) continue;
      // up
      if(j != 0){
        ll ad = 0;
        if (bonus[i+1].first == j-1) ad = bonus[i+1].second;
        chmax(dp[i+1][j-1], dp[i][j]+ad);
      }
      // todomaru
      ll ad_todo = 0;
      if (bonus[i+1].first == j) ad_todo = bonus[i+1].second;
      chmax(dp[i+1][j], dp[i][j]+ad_todo);

      // down
      if(j != 4){
        ll ad_down = 0;
        if (bonus[i+1].first == j+1) ad_down = bonus[i+1].second;
        chmax(dp[i+1][j+1], dp[i][j]+ad_down);
      }
    }
  }



  ll ans = 0;
  rep(i, 5) chmax(ans, dp[max_t][i]);
  cout << ans << endl;
}
