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
ll arr[110];
ll dp[110][22] = {0};

int main(){
  cin >> n;
  rep(i, n){
    cin >> arr[i];
  }

  dp[0][arr[0]] = (ll)1;

  rep(i, n-1){
    rep(j, 21){
      if(j + arr[i+1] < 21) dp[i+1][j + arr[i+1]] += dp[i][j];
      if(j - arr[i+1] >= 0) dp[i+1][j - arr[i+1]] += dp[i][j];
    }
  }

  cout << dp[n-2][arr[n-1]] << endl;
}
