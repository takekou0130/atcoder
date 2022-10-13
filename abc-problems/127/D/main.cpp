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

int n,m;
ll a[101010];
// c , b
vector<P> bc;
ll ans = 0;

int main(){
  cin >> n >> m;
  rep(i, n) cin >> a[i];
  rep(i, m) {
    ll b,c;
    cin >> b >> c;
    bc.push_back({c,b});
  }

  sort(a,a+n);
  sort(bc.begin(),bc.end());
  reverse(bc.begin(), bc.end());

  ll idx = 0;
  for(auto bci: bc){
    int tar = lower_bound(a+idx, a+n, bci.first) - a;
    if(tar - idx == 0) break;
    if(tar - idx > bci.second) {
      ans += bci.second * bci.first;
      idx += bci.second;
    } else {
      ans += (tar-idx) * bci.first;
      idx = tar;
    }
  }
  rep2(i, idx, n) ans += a[i];
  cout << ans << endl;
}
