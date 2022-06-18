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

int n,m,k;
char field[1010][1010];
// joi
ll dp[1010][1010][3];

int main(){
  cin >> m >> n >> k;
  rep(i, m){
    string s;
    cin >> s;
    rep(j, n){
      field[i][j] = s[j];
    }
  }
  rep(i, 1010) rep(j, 1010) rep(k, 3) dp[i][j][k] = 0;

  rep(i, m) {
    rep(j, n) {
      if (field[i][j] == 'J') dp[i][j][0]++;
      if (field[i][j] == 'O') dp[i][j][1]++;
      if (field[i][j] == 'I') dp[i][j][2]++;
      rep(l, 3) {
        dp[i][j+1][l] += dp[i][j][l];
        dp[i+1][j][l] += dp[i][j][l];
        dp[i+1][j+1][l] -= dp[i][j][l];
      }
    }
  }

  rep(i, k){
    int a, b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    rep(j, 3){
      ll ans = 0;
      ans += dp[c][d][j];
      if(a-1 >= 0) ans -= dp[a-1][d][j];
      if(b-1 >= 0) ans -= dp[c][b-1][j];
      if(a-1 >= 0 && b-1 >= 0) ans += dp[a-1][b-1][j];
      if(j == 0 || j == 1) cout << ans << " ";
      else cout << ans << endl;
    }
  }
}
