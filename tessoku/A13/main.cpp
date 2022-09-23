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

int n;
ll k;
ll a[101010], r_i[101010];

int main(){
  cin >> n >> k;
  rep(i, n) cin >> a[i];

  int r = 0;
  rep(l, n-1) {
    while(r < n && a[r]-a[l] <= k) {
      r++;
    }

    r_i[l] = r - 1;

    if(l == r) r++;
  }

  ll ans = 0;
  rep(l, n-1) ans += r_i[l] - l;
  cout << ans << endl;
}
