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

int n,m;
ll a[101010];
ll sum[101010];
ll ans = 0;
ll mod = 100000;

int main(){
  cin >> n >> m;
  rep(i, n-1) cin >> a[i];
  sum[0] = 0;
  rep(i, n-1) sum[i+1] = sum[i] + a[i];
  ll now = 0;
  rep(i, m){
    int k;
    cin >> k;
    ans += abs(sum[now+k] - sum[now]);
    ans %= mod;
    now += k;
  }

  cout << ans << endl;
}
