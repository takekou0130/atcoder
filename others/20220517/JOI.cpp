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

int d, n;
int t[210];
vector<int> arr[210];
int dp[210][210];

int main(){
  cin >> d >> n;
  rep(i, d) cin >> t[i];
  rep(j, n) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[j].push_back(a);
    arr[j].push_back(b);
    arr[j].push_back(c);
  }

  rep(i, 210) rep(j,210) dp[i][j] = -1;

  rep(j, n){
    if(arr[j][0] <= t[0] && t[0] <= arr[j][1]) dp[0][j] = 0;
  }

  rep(i, d) {
    rep(j, n){
      if(dp[i][j] == -1) continue;

      // 配る
      rep(k, n){
        if(arr[k][0] <= t[i+1] && t[i+1] <= arr[k][1]) chmax(dp[i+1][k], dp[i][j] + abs(arr[j][2] - arr[k][2]));
      }
    }
  }

  int ans = -1;
  rep(j, n) chmax(ans , dp[d-1][j]);
  cout << ans << endl;
}
