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
ll a[201010];
ll sum[201010];
map<ll, ll> mp;
int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n+5) sum[i] = 0;
  rep(i, n) sum[i+1] = sum[i] + a[i];
  rep2(i, 0, n+1) mp[sum[i]]++;
  ll ans = 0;
  for(auto m: mp){
    if(m.second % 2LL == 0) ans += ((m.second) / 2LL)  * (m.second - 1LL);
    else ans += ((m.second - 1LL) / 2LL) * m.second;
  }
  cout << ans << endl;
}
