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

ll ans = 1e10;
int n;

int main(){
  cin >> n;
  rep(i, n){
    ll a,p,x;
    cin >> a >> p >> x;
    if(x > a) chmin(ans,p);
  }

  if(ans == 1e10) cout << -1 << endl;
  else cout << ans << endl;
}
