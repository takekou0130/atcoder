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

ll a,b,c,d,e,f;
ll mod = 998244353;
int main(){
  cin >> a >> b >> c >> d >> e >> f;
  ll saki = (((a%mod) * (b%mod)) % mod * (c%mod)) % mod;
  ll ato = (((d%mod) * (e%mod)) % mod * (f%mod)) % mod;
  ll sa = ((saki - ato) + mod) % mod;
  cout << sa % mod << endl;
}
