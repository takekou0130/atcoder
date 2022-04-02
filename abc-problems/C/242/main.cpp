#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int mod = 998244353;
int n;
int dp[9][1010101] = {0};

int main(){
  cin >> n;
  rep(i, 9){
    dp[i][0] = 1;
  }
  rep2(i, 1, n){
    rep(j, 9){
      if(j == 0) dp[j][i] = (dp[0][i-1] + dp[1][i-1]) % mod;
      else if(j == 8) dp[j][i] = (dp[7][i-1] + dp[8][i-1]) % mod;
      else{
        ll sum = (dp[j][i-1] + dp[j-1][i-1]) % mod;
        sum += dp[j+1][i-1];
        dp[j][i] = sum % mod;
      }
    }
  }
  int ans = 0;
  rep(i, 9){
    ans += dp[i][n-1];
    ans %= mod;
  }
  cout << ans << endl;
}
