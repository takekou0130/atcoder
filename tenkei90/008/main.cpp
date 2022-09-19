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
string s;
string at = "atcoder";
ll dp[101010][10];
ll mod = 1000000007;

int main(){
  cin >> n >> s;
  // j = 0は何も選んでいないとき
  rep(i, 101010) rep(j,8) dp[i][j] = 0;
  if(n < 7) {
    cout << 0 << endl;
    return 0;
  }
  dp[0][0] = 1;
  if(s[0] == 'a') dp[0][1] = 1;
  rep(i, n-1) rep(j, 8){
    dp[i+1][j] += dp[i][j];
    dp[i+1][j] %= mod;
    if(j < 8 && s[i+1] == at[j]){
      dp[i+1][j+1] += dp[i][j];
      dp[i+1][j+1] %= mod;
    }
  }

  cout << dp[n-1][7] << endl;
}
