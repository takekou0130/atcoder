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
ll a[202020];
ll v[202020];
ll sum[202021];

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, 202020) v[i] = 0, sum[i] = 0;
  rep(i, n) v[a[i] - 1]++;
  rep(i, 202020) sum[i+1] = sum[i] + v[i];
  ll ans = 0;
  rep2(i, 1, 202020) {
    ans += v[i] * (sum[i] - sum[0]) * (sum[202020] - sum[i+1]);
  }
  cout << ans << endl;
}
