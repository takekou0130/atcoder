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

int h,w;
ll dp[10][10];
int need[10] = {0};

int main(){
  cin >> h >> w;
  rep(i, 10) rep(j, 10) cin >> dp[i][j];

  // ワーシャルフロイド
  rep(k, 10){
    rep(i, 10){
      rep(j, 10){
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
      }
    }
  }

  rep(i, h) rep(j, w){
    int a;
    cin >> a;
    need[a]++;
  }
  ll ans = 0;
  rep(i, 10) ans += need[i] * dp[i][1];
  cout << ans << endl;
}
