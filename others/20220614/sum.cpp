
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
ll a[3030];
ll sum[3030];
int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n+2) sum[i] = 0;
  rep(i, n) sum[i+1] = sum[i] + a[i];
  rep2(i, 1, n+1){
    ll ans = 0;
    for(int j = 0; j < n+1; j++){
      if(j+i > n) continue;
      chmax(ans, sum[j+i] - sum[j]);
    }
    cout << ans << endl;
  }
}
