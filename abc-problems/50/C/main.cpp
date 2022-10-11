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

ll n;
int a[101010];

ll modpow(ll base, ll N, ll mod) {
  ll ans = 1;
  while(N > 0) {
    if(N & 1){
      ans *= base;
      ans %= mod;
    }
    base = (base * base) % mod;
    N /= 2;
  }
  return ans;
}

int main(){
  cin >> n;
  rep(i, 101010) a[i] = 0;
  rep(i, n){
    int in;
    cin >> in;
    a[in]++;
  }
  if(n%2 == 1) {
    rep(i, n) {
      if(i == 0){
        if(a[i] != 1) {
          cout << 0 << endl;
          return 0;
        }
      }
      else if(i%2 == 1) {
        if(a[i] != 0) {
          cout << 0 << endl;
          return 0;
        }
      }
      else if(i%2 == 0) {
        if(a[i] != 2) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
    cout << modpow(2, (n-1)/2, 1000000007) << endl;
  }
  if(n%2 == 0) {
    rep(i, n) {
      if(i%2 == 1) {
        if(a[i] != 2) {
          cout << 0 << endl;
          return 0;
        }
      }
      else if(i%2 == 0) {
        if(a[i] != 0) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
    cout << modpow(2, n/2, 1000000007) << endl;
  }
}
