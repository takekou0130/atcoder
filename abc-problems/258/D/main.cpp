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

ll n, x;
ll a[202020], b[202020];
// i番目までのBの最小値
ll b_min[202020];
int main(){
  cin >> n >> x;
  rep(i, n) cin >> a[i] >> b[i];
  ll sum_ab = a[0]+b[0];
  b_min[0] = b[0];
  rep2(i, 1, min(n, x)) {
    b_min[i] = min(b_min[i-1], b[i]);
    sum_ab += a[i]+b[i];
  }
  ll ans = sum_ab + b_min[min(n,x)-1]*(x - min(n,x));
  for(int i = min(n,x)-1; i >= 0; i--){
    chmin(ans, sum_ab+b_min[i]*(x-(i+1)));
    sum_ab -= (a[i]+b[i]);
  }
  cout << ans << endl;
}
