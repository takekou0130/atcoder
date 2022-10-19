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
int x,y;
int a[303],b[303];
// n, a, b
int dp[303][303][303];

int main(){
  cin >> n >> x >> y;
  rep(i, 303) rep(j, 303) rep(k, 303) dp[i][j][k] = -1;
  rep(i, n) cin >> a[i] >> b[i];

  dp[0][0][0] = 0;
  dp[0][a[0]][b[0]] = 1;
  rep(i, n-1) {
    rep(j, x+1) {
      rep(k, y+1) {
        if(dp[i][j][k] == -1) continue;

        if(dp[i+1][j][k] == -1) dp[i+1][j][k] = dp[i][j][k];
        else chmin(dp[i+1][j][k], dp[i][j][k]);

        if(dp[i+1][min(j+a[i+1], x)][min(k+b[i+1], y)] == -1) dp[i+1][min(j+a[i+1], x)][min(k+b[i+1], y)] = dp[i][j][k] + 1;
        else chmin(dp[i+1][min(j+a[i+1], x)][min(k+b[i+1], y)], dp[i][j][k]+1);
      }
    }
  }

  cout << dp[n-1][x][y] << endl;

}
