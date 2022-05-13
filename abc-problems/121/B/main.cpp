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

int n,m,c;
int b[21];
int a[21][21];

int main(){
  cin >> n >> m >> c;
  rep(i, m) cin >> b[i];
  rep(i, n) rep(j, m) cin >> a[i][j];
  int ans = 0;
  rep(i, n) {
    int result = 0;
    rep(j, m) result += b[j] * a[i][j];
    result += c;
    if(result > 0) ans++;
  }
  cout << ans << endl;
}
