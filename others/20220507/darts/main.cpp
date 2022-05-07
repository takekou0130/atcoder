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

vector<ll> doub;
vector<ll> v;
ll n, m;

int main(){
  cin >> n >> m;
  v.push_back(0);
  rep(i, n){
    ll in;
    cin >> in;
    v.push_back(in);
  }
  rep(i, v.size()) rep(j, v.size()) {
    if(v[i] + v[j] > m) continue;
    doub.push_back(v[i] + v[j]);
  }
  sort(doub.begin(), doub.end());

  ll ans = 0;

  rep(i, doub.size()){
    ll rest = m - doub[i];
    ll ok = 0;
    ll ng = doub.size();
    while(ng - ok > 1){
      ll mid = ok + (ng - ok) / 2;
      if(doub[mid] > rest){
        ng = mid;
      } else {
        ok = mid;
      }
    }
    chmax(ans, doub[ok]+doub[i]);
  }

  cout << ans << endl;
}
