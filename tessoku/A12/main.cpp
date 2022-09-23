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
ll a[101010];

bool check(ll t) {
  ll tot = 0;
  rep(i, n) {
    tot += t / a[i];
  }
  return tot >= k;
}

int main(){
  cin >> n >> k;
  rep(i, n) cin >> a[i];

  ll ok = 1e9 + 1LL;
  ll ng = 0;
  while(ok - ng > 1) {
    ll mid = ng + (ok - ng) / 2LL;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
