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

int n,m;
int a[101];
int dp[2020][109];
int inf = 1e9;

int main(){
  cin >> n >> m;
  rep(i, m) {
    int in = 0;
    for(int j = n-1; j >= 0; j--) {
      int bit;
      cin >> bit;
      if(bit) in += (1 << j);
    }
    a[i] = in;
  }

  rep(i, 2020) rep(j, 109) dp[i][j] = inf;

  dp[0][0] = 0;

  rep(j, m) {
    rep(i, pow(2, n)) {
      if(dp[i][j] == inf) continue;

      chmin(dp[i][j+1], dp[i][j]);
      chmin(dp[i|a[j]][j+1], dp[i][j]+1);
    }
  }
  if (dp[(1 << n) - 1][m] == inf) cout << -1 << endl;
  else cout << dp[(1 << n) - 1][m] << endl;
}
