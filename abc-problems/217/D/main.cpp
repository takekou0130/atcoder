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

ll l,q;
set<ll> cut;

int main(){
  cin >> l >> q;
  rep(i, q) {
    int c;
    ll x;
    cin >> c >> x;
    cut.insert(0LL);
    cut.insert(l);
    if(c == 1) {
      cut.insert(x);
    } else {
      auto itr = cut.upper_bound(x);
      ll ans = *itr;
      itr--;
      cout << ans - *itr << endl;
    }
  }
}
