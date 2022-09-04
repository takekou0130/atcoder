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

ll n,m;
ll a[202020];
ll sum[202021];

int main(){
  cin >> n >> m;
  rep(i, n) cin >> a[i];

  sum[0] = 0;
  rep(i, n) sum[i+1] = sum[i] + a[i];

  ll ans = 0;
  rep(i, m){
    ans += a[i] * (i+1);
  }

  if(n == m){
    cout << ans << endl;
    return 0;
  }

  ll tot = ans;
  cout << "tot" << tot << endl;
  for(int i = 1; i+m-1 < n ; i++){
    tot -= sum[i+m-1] - sum[i-1];
    tot += m*a[i+m-1];
    cout << "to" << tot << endl;
    chmax(ans, tot);
  }

  cout << ans << endl;
}
