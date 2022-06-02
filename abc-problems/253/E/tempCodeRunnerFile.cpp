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

ll n,m,k;
ll mod = 998244353;
ll dp[1010][5050];
ll sum[5050];

int main(){
  cin >> n >> m >> k;
  rep(i, 1010) rep(j, 5050){
    dp[i][j] = 0;
    sum[j] = 0;
  }
  rep(j, m+1){
    dp[0][j] = 1;
  }
  dp[0][0] = 0;

  rep2(i, 1, n+1){
    rep2(j, 1, m+1){
      sum[j] = sum[j-1] + dp[i-1][j];
      sum[j] %= mod;
    }

    rep2(j, 1, m+1){
      if(j > k){
        dp[i][j] += sum[j-k];
        dp[i][j] %= mod;
      }
      if(j+k <= m){
        dp[i][j] += sum[m] - sum[j+k-1];
        dp[i][j] %= mod;
      }
    }
  }


  ll sum = 0;
  rep2(j,1, m+1){
    sum += dp[n-1][j];
    sum %= mod;
  }

  cout << sum << endl;
}
