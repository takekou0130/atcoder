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
ll a[101010];
bool prime[101010];
vector<ll> primes;

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];

  rep(i, 101010) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
  for(ll i = 2; i <101010; i++){
    if(!prime[i]) continue;
    for(ll j = i*2; j < 101010; j += i){
      prime[j] = false;
    }
  }
  for(ll i = 0; i < n+1; i++){
    if(prime[i]) primes.push_back(i);
  }

  ll ans = 1;
  for(auto p: primes){
    bool flag = false;
    bool flag2 = true;
    rep(i, n){
      if(a[i] % p == 0) continue;
      if(flag){
        flag2 = false;
        break;
      }
      flag = true;
    }
    if(flag2) chmax(ans, p);
  }

  cout << ans << endl;
}
