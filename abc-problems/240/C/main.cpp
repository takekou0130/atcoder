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

int n,x;
int a[101],b[101];
bool dp[101][10101];
int main(){
  cin >> n >> x;
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, 101) rep(j, 10101) dp[i][j] = false;
  dp[0][0] = true;
  rep(i, n){
    rep(j, x){
      if(dp[i][j]){
        dp[i+1][a[i]+j] = true;
        dp[i+1][b[i]+j] = true;
      }
    }
  }

  if(dp[n][x]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
