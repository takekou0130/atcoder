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
int h[101010];
ll dp[101010] = {0};

int main(){
  cin >> n;
  rep(i, n) cin >> h[i];
  dp[0] = 0;
  dp[1] = abs(h[0] - h[1]);
  rep(i, n-2){
    dp[i+2] = min(dp[i]+abs(h[i] - h[i+2]), dp[i+1]+abs(h[i+1]-h[i+2]));
  }
  cout << dp[n-1] << endl;
}
