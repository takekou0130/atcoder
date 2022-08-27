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

ll n, p, q, r;
ll a[202020];
ll sum[202020];
int main(){
  cin >> n >> p >> q >> r;
  rep(i, n) cin >> a[i];

  sum[0] = 0;
  rep(i, n) sum[i+1] = sum[i] + a[i];

  rep(x, n-2){
    int y_idx = lower_bound(sum+(x+1), sum+n, sum[x]+p) - sum;
    if (y_idx > n || sum[y_idx] - sum[x] != p){
      continue;
    }

    int z_idx = lower_bound(sum+(y_idx+1), sum+n, sum[y_idx]+q) - sum;
    if (z_idx > n || sum[z_idx] - sum[y_idx] != q){
      continue;
    }

    int w_idx = lower_bound(sum+(z_idx+1), sum+n, sum[z_idx]+r) - sum;
    if (w_idx > n || sum[w_idx] - sum[z_idx] != r){
      continue;
    }

    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
}
