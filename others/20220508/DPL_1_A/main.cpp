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

int n, m;
int dp[21][50505];
vector<int> coin;

int main(){
  cin >> n >> m;
  rep(i, m){
    int c;
    cin >> c;
    coin.push_back(c);
  }

  sort(coin.begin(), coin.end());

  // 0円のときは0枚
  rep(i, m) dp[i][0] = 0;
  // 1枚目は必ず1円なのでj枚必要
  rep(j, n+1) dp[0][j] = j;

  rep2(i,1, m) {
    rep2(j, 1, n+1) {
      if (coin[i] > j){
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = min(dp[i-1][j], dp[i][j-coin[i]]+1);
      }
    }
  }

  cout << dp[m-1][n] << endl;
}
