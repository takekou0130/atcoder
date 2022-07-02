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

ll ans = 1e18;
ll n;
ll x[101];
int main(){
  cin >> n;
  rep(i, n) cin >> x[i];

  rep2(i, 1, 101){
    ll sum = 0;
    rep(j, n){
      sum += (x[j] - i) * (x[j] - i);
    }
    chmin(ans, sum);
  }
  cout << ans << endl;
}
