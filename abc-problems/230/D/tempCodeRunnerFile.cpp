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
ll d;
vector<P> p;

int main(){
  cin >> n >> d;
  rep(i, n) {
    ll l,r;
    cin >> l >> r;
    p.push_back({r,l});
  }

  sort(p.begin(), p.end());

  ll ans = 0;
  ll nxr = -1e18;
  for(auto [r, l]: p){
    if(nxr <= r){
      ans++;
      nxr = r + d;
    }
  }

  cout << ans << endl;
}
