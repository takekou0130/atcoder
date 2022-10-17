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
ll a[101];
ll c[202];
vector<ll> b;

int main(){
  cin >> n >> m;
  rep(i, n+1) cin >> a[i];
  rep(i, n+m+1) cin >> c[i];
  reverse(a, a+n+1);
  reverse(c, c+n+m+1);

  rep(i, m+1){
    ll b_i = c[i] / a[0];
    b.push_back(b_i);
    rep(j, n+1) {
      c[i+j] -= a[j] * b_i;
    }
  }

  reverse(b.begin(), b.end());
  rep(i, m+1){
    cout << b[i];
    if(i != m) cout << " ";
  }
  cout << endl;
}
