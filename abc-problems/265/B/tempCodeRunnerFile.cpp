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

ll n,m,t;
ll a[101010], bonus[101010];

int main(){
  cin >> n >> m >> t;
  rep(i, n-1) cin >> a[i];
  rep(i, n) bonus[i] = 0;
  rep(i, m){
    ll x,y;
    bonus[x] = y;
  };

  rep(i, n-1) {
    if(a[i] < t){
      t -= a[i];
      t += bonus[i+2];
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
