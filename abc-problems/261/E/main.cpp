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

ll n,c;
ll t[202020],a[202020];
ll sum[202020][2];
ll zero = 0LL;
ll inf = (1<<30) - 1LL;

int main(){
  cin >> n >> c;
  rep(i, n) cin >> t[i] >> a[i];
  sum[0][0] = zero;
  sum[0][1] = inf;
  rep(i, n) rep(j, 2) {
    if(t[i] == 1){
      sum[i+1][j] = sum[i][j] & a[i];
    }
    if(t[i] == 2){
      sum[i+1][j] = sum[i][j] | a[i];
    }
    if(t[i] == 3){
      sum[i+1][j] = sum[i][j] ^ a[i];
    }
  }

  rep(i, n){
    ll base = 0;
    rep(j,30){
      if(c & (1<<j)){
        if (sum[i+1][1] & (1<<j)){
          base += (1<<j);
        }
      }
      else {
        if (sum[i+1][0] & (1<<j)){
          base += (1<<j);
        }
      }
    }
    cout << base << endl;
    c = base;
  }

}
