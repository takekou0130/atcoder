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
ll a[202020];
ll sum[202020];

int main(){
  cin >> n >> q;
  rep(i, n) cin >> a[i];
  sort(a, a+n);
  sum[0] = 0;
  rep(i, n) sum[i+1] = sum[i] + a[i];
  rep(i, q){
    ll x;
    cin >> x;
    int idx = lower_bound(a,a+n, x) - a;
    ll ans = 0;

    if(idx != 0){
      ll s = sum[idx] - sum[0];
      ans += x * idx - s;
    }

    if(idx != n){
      ll s = sum[n] - sum[idx];
      ans += s - x * (n-idx);
    }

    cout << ans << endl;
  }
}


