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

ll mod = 10000;
int n,k;
int arr[101];
ll dp[110][3][3] = {0};

int main(){
  cin >> n >> k;
  rep(i, n) arr[i] = -1;
  rep(i, k) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    arr[a] = b;
  }

  if (arr[0] == -1){
    rep(j, 3) rep(k,3) dp[1][j][k] = 1;
  }
  if (arr[0] != -1){
    rep(j,3) dp[1][j][arr[0]] = 1;
  }

  rep2(i, 1, n){
    // まず決まっている場合、不適なものを消す
    if(arr[i] != -1){
      rep(j, 3) rep(k, 3) {
        if(arr[i] == j) continue;
        dp[i][j][k] = 0;
      }
    }

    // 配る
    rep(j, 3){
      rep(k, 3){
        rep(l, 3){
          if(j == k && j == l) continue;
          dp[i+1][l][j] += dp[i][j][k];
          dp[i+1][l][j] %= mod;

        }
      }
    }
  }

  ll ans = 0;
  rep(j, 3) rep(k, 3) {
    ans += dp[n-1][j][k];
    ans %= mod;
  }
  cout << ans << endl;
}
