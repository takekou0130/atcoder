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

ll n, l, r;

ll a[202020];

int main(){
  cin >> n >> l >>r;
  rep(i, n) cin >> a[i];
  a[n] = 0;

  ll ans = 1e18;
  ll lmin = 0;
  ll lsum = 0;

  rep(y, n+1) {
    ll tot = (n - y) * r;
    if(y > 0){
      lmin = min(lmin+a[y-1], y*l);
    }
    chmin(ans, tot+lmin);
  }
  cout << ans << endl;
}
