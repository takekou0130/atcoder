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
ll a[2][101010];
ll sum[2][101010];

int main(){
  rep(i,n)rep(j,2){
    a[j][i] = 0;
  }
  cin >> n;
  rep(i, n){
    int c;
    ll p;
    cin >> c >> p;
    c--;
    a[c][i] = p;
  }

  sum[0][0] = 0;
  sum[1][0] = 0;

  rep(i, n){
    sum[0][i+1] = sum[0][i] + a[0][i];
    sum[1][i+1] = sum[1][i] + a[1][i];
  }

  int q;
  cin >> q;
  rep(i, q){
    int l,r;
    cin >> l >> r;
    l--; r--;
    cout << sum[0][r+1] - sum[0][l] << " " << sum[1][r+1] - sum[1][l] << endl;
  }
}
