#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll dp[51][2501] = {0};
ll n, m, k;
ll mod = 998244353;

int main(){
  cin >> n >> m >> k;
  n--;
  k--;
  rep(i, k+1){
    if(i+1 <= m) dp[0][i] = 1;
  }
  rep(i, k+1){
    rep(j, n+1){
      rep2(l, i+1, k+1){
        if(l - i <= m) dp[j+1][l] += dp[j][i];
        dp[j+1][l] %= mod;
      }
    }
  }

  ll ans = 0;
  rep(i, k+1){
    ans += dp[n][i];
    ans %= mod;
  }
  cout << ans << endl;
}
