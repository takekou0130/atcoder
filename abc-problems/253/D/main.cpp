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

ll n, a, b;



int main(){
  cin >> n >> a >> b;
  ll A = n / a;
  ll B = n / b;
  ll ab = lcm(a,b);
  ll AB = n / ab;

  ll ans = 0;
  ans -= A * (2LL * a + (A - 1LL) * a) / 2LL;
  ans += n * (1LL + n) / 2LL;
  ans -= B * (2LL * b + (B - 1) * b) / 2LL;
  ans += AB * (2LL * ab + (AB -1)* ab) / 2LL;
  cout << ans << endl;
}
