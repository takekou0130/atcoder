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

int n,k;
ll l;
ll a[101010];
ll sum[101011];

bool check(ll mid){
  int start = 0;
  int c_k = 0;
  rep(i, n+2){
    if(sum[i] - sum[start] >= mid){
      c_k++;
      start = i;
    }

    if(c_k >= k+1) return true;
  }
  return false;
}

int main(){
  cin >> n >> l >> k;
  rep(i, n) cin >> a[i];
  sum[0] = 0LL;
  rep(i, n) sum[i+1] = a[i];
  sum[n+1] = l;

  ll ng = 1e18;
  ll ok = 1LL;
  while(ng - ok > 1LL){
    ll mid = ok + (ng-ok) / 2LL;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
