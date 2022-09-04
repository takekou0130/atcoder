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

ll n,m;
vector<ll> a;

int main(){
  cin >> n >> m;
  rep(i, n) {
    ll an; cin >> an; a.push_back(an/2);
  }

  ll lcmnum = 1;
  rep(i, n) lcmnum = lcm(lcmnum, a[i]);
  if (lcmnum > m) cout << 0 << endl; return 0;
  cout << (m/lcmnum-1)/2+1 << endl;
}
