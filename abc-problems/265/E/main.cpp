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

ll mod = 998244353;
map<P, ll> dp;
ll n,m,a,b,c,d,e,f;
set<P> batu;

int main(){
  cin >> n >> m >> a >> b >> c >> d >> e >> f;
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    batu.insert({x,y});
  }

  dp[{0,0}] = 1LL;

  rep(i, n){
    map<P, ll> new_dp;
    for(auto mp: dp){
      ll x_tmp = mp.first.first;
      ll y_tmp = mp.first.second;
      if (!batu.count({x_tmp+a,y_tmp+b})){
        new_dp[{x_tmp + a,y_tmp+b}] += mp.second;
        new_dp[{x_tmp + a,y_tmp+b}] %= mod;
      }
      if (!batu.count({x_tmp+c,y_tmp+d})){
        new_dp[{x_tmp+c,y_tmp+d}] += mp.second;
        new_dp[{x_tmp+c,y_tmp+d}] %= mod;
      }
      if (!batu.count({x_tmp+e,y_tmp+f})){
        new_dp[{x_tmp+e,y_tmp+f}] += mp.second;
        new_dp[{x_tmp+e,y_tmp+f}] %= mod;
      }
    }
    dp = new_dp;
  }

  ll tot = 0;
  for(auto mp: dp){
    tot += mp.second;
    tot %= mod;
  }

  cout << tot << endl;
}
