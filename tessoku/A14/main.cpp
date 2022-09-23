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
ll k;
ll a[1010],b[1010],c[1010],d[1010];
set<ll> ab;
set<ll> cd;

int main(){
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  rep(i, n) cin >> d[i];

  rep(i, n) rep(j, n) ab.insert(a[i]+b[j]);
  rep(i, n) rep(j, n) cd.insert(c[i]+d[j]);

  for(auto s: ab){
    if(cd.count(k-s)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}
