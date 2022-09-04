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
ll a[2020];
ll dp[2020][2020];
ll minf = -2e12;

int main(){
  cin >> n >> m;
  rep(i,n) cin >> a[i];

  rep(i, 2020) rep(j, 2020) dp[i][j] = minf;

  dp[0][0] = 0;
  dp[0][1] = a[0];
  rep(i, n-1) {
    rep(j, m+1) {
      if(dp[i][j] == minf) continue;

      chmax(dp[i+1][j],dp[i][j]);
      chmax(dp[i+1][j+1],dp[i][j]+(j+1)*a[i+1]);
    }
  }

  cout << dp[n-1][m] << endl;
}
