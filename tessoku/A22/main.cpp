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
ll a[101010],b[101010];
ll dp[101020];

int main(){
  cin >> n;
  rep(i, n-1) {cin >> a[i]; a[i]--;}
  rep(i, n-1) {cin >> b[i]; b[i]--;}
  rep(i, 101020) dp[i] = -1;
  dp[0] = 0;

  rep(i, n-1) {
    if(dp[i] != -1) chmax(dp[a[i]], dp[i]+100);
    if(dp[i] != -1) chmax(dp[b[i]], dp[i]+150);
  }

  cout << dp[n-1] << endl;
}
