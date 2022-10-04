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
int p[2020],a[2020];
int dp[2020][2020];

int main(){
  cin >> n;
  rep(i, n) {
    int p_in;
    cin >> p_in >> a[i];
    p_in--; p[i] = p_in;
  }

  rep(i, 2020) rep(j, 2020) dp[i][j] = 0;

  for(int len = n; len >= 0; len--) {
    rep(lef, n+1) {
      int rig = len + lef;
      if (rig > n) continue;

      int sco = 0;
      // lefを取り除くとき
      if(lef != 0) chmax(sco, dp[lef-1][rig]+(p[lef-1] >= lef && p[lef-1] < rig ? a[lef-1] : 0));

      // rigを取り除くとき
      if(rig != n) chmax(sco, dp[lef][rig+1]+(p[rig] >= lef && p[rig] < rig ? a[rig] : 0));

      chmax(dp[lef][rig],sco);
    }
  }

  int ans = 0;
  rep(i, n+1) chmax(ans, dp[i][i]);
  cout << ans << endl;
}
