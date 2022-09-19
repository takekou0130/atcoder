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
ll a[3];

int main(){
  cin >> n >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  reverse(a,a+3);
  ll ans = 10000;
  rep(i, 10000) rep(j, 10000-i){
    ll rest = n - a[0]*i - a[1]*j;
    if(rest >= 0 && rest % a[2] == 0) chmin(ans, i+j+(rest/a[2]));
  }
  cout << ans << endl;
}
