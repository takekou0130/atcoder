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

ll n,q;
ll a[121212], c[121212];
ll mpow[121212];
ll sum[121212];
ll mod = 1000000007;

ll modpow(ll base, ll m) {
  ll ans = 1LL;
  while(m > 0){
    if(m & 1) ans = base * ans % mod;
    base = base * base % mod;
    m >>= 1;
  }
  return ans;
}

int main(){
  cin >> n >> q ;
  rep(i, n) cin >> a[i];
  rep(i, q){cin >> c[i]; c[i]--;}

  rep(i, n-1) mpow[i] = modpow(a[i], a[i+1]);
  sum[0] = 0LL;
  rep(i, n-1) sum[i+1] = (mpow[i] + sum[i]) % mod;

  ll ans = 0LL;
  ll now = 0;
  rep(i, q){
    ans += sum[max(now, c[i])] - sum[min(now, c[i])] + mod;
    ans %= mod;
    now = c[i];
  }
  ans += sum[now];
  ans %= mod;
  cout << ans << endl;
}
