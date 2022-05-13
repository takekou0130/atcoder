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

int n, k;
int h[101010];
ll dp[101010];

int main(){
  cin >> n >> k;
  rep(i,n) cin >> h[i];
  rep(i,n+200) dp[i] = 1e18;
  dp[0] = 0;
  rep(i, n){
    rep(j, k){
      dp[i+j+1] = min(dp[i+j+1], dp[i]+abs(h[i] - h[i+j+1]));
    }
  }
  cout << dp[n-1] << endl;
}
