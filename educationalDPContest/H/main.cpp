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

int h,w;
ll dp[1010][1010] = {0};
char field[1010][1010];
ll mod = 1000000007;

int main(){
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> field[i][j];
  dp[0][0] = 1;
  rep(i, h) rep(j, w) {
    if(field[i][j] == '#') continue;
    dp[i+1][j] += dp[i][j]; dp[i+1][j] %= mod;
    dp[i][j+1] += dp[i][j]; dp[i][j+1] %= mod;
  }

  cout << dp[h-1][w-1] << endl;
}
