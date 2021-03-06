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
    ll k = i;
    for(ll j = 2; j*j <= k; j++){
      while(k % (j*j) == 0){
        k /= (j * j);
      }
    }
    for(ll j = 1; k*j*j <= n; j++){
      ans++;
    }
  }
  cout << ans << endl;
}
