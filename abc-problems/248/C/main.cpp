#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll dp[2502][2502] = {0};
ll n, m, k;
ll mod = 998244353;

int main(){
  cin >> n >> m >> k;
  rep2(i, 1, k+1){
    if (i <= m) dp[0][i] = 1;
  }

  rep2(i, 1, k+1){
    rep2(j, 1, n){
      ll sum = 0;
      rep2(l, 1, i){
        if(i - l <= m){
          sum += dp[j-1][l];
          sum %= mod;
        }
      }
      dp[j][i] = (sum % mod);
    }
  }

  ll ans = 0;
  rep2(i, 1, k+1){
    ans += dp[n-1][i];
    ans %= mod;
  }
  cout << ans << endl;
}
