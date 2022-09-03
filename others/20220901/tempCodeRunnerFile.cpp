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

ll m,n;
ll mod = 1000000007;

int main(){
  cin >> m >> n;
  ll ans = 1LL;
  while(n > 0) {
    if(n & 1) {
      ans = ans * m % mod;
      m = m * m % mod;
    }
    n >>= 1;
  }
  cout << ans << endl;
}
