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

ll n,m,Q;
ll sum[505][505];
int main(){
  cin >> n >> m >> Q;
  rep(i, n+1) rep(j, n+1) sum[i][j] = 0;
  rep(i, m){
    ll l,r;
    cin >> l >> r;
    sum[l][r]++;
  }

  rep(i, n) rep(j, n) {
    sum[i+1][j+1] = sum[i+1][j+1] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
  }

  rep(i, Q) {
    ll p,q;
    cin >> p >> q;
    cout << sum[q][q] - sum[p-1][q] - sum[q][p-1] + sum[p-1][p-1] << endl;
  }
}
