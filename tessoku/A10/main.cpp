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
int a[101010], l_m[101010], r_m[101010];
int d;
int l[101010],r[101010];

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  cin >> d;
  rep(i, d) cin >> l[i] >> r[i];

  int m = 0;
  rep(i, n) {
    chmax(m,a[i]);
    l_m[i] = m;
  }

  m = 0;
  for(int i = n-1; i >= 0; i--) {
    chmax(m,a[i]);
    r_m[i] = m;
  }

  rep(i, d) {
    int l_ma = 0;
    int r_ma = 0;
    if(l[i] > 1) l_ma = l_m[l[i]-2];
    if(r[i] != n) r_ma = r_m[r[i]];
    cout << max(l_ma,r_ma) << endl;
  }
}
