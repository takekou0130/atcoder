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

int n, w;
// w vの順
ll wv[101][2];
ll dp[101][101010];

int main(){
  cin >> n >> w;
  rep(i, n){
    cin >> wv[i][0] >> wv[i][1];
  }
  rep(j, w+1){
    if (j >= wv[0][0]) dp[0][j] = wv[0][1];
    else dp[0][j] = 0;
  }

  rep(j, w+1){
    rep(i, n-1){
      if(j < wv[i+1][0]) dp[i+1][j] = dp[i][j];
      else {
        dp[i+1][j] = max(dp[i][j], dp[i][j-wv[i+1][0]]+wv[i+1][1]);
      }
    }
  }

  cout << dp[n-1][w] << endl;
}
