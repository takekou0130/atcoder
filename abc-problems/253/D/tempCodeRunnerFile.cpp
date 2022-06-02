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
  ll ans = n * (1 + n) / 2;
  ll A = n / a;
  ll B = n / b;
  ll ab = lcm(a,b);
  ll AB = n / ab;

  ans -= A * (2 * a + (A - 1) * a) / 2;

  ans -= B * (2 * b + (B - 1) * b) / 2;

  ans += AB * (2 * ab + (AB -1)* ab) / 2;
}
