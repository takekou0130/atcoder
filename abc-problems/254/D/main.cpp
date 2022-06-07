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

ll ans = 0;
ll n;

int main(){
  cin >> n;
  for(ll i = 1; i <= n; i++){
    ll tar = i*i;
    for(ll j = tar / n; j*j <= tar && j <= n; j++){
      if(tar % j == 0 && tar / j <= n && tar / j == j) {
        ans++;
      }
      if(tar % j == 0 && tar / j <= n && tar / j != j) {
        ans += 2LL;
      }
    }
  }
  cout << ans << endl;
}
