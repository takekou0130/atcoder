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
map<ll, ll> imos;
ll ans[202020];

int main(){
  cin >> n;
  rep(i, n) {
    ll a,b;
    cin >> a >> b;
    a--;
    imos[a]++;
    imos[a+b]--;
  }

  rep(i, n+2) ans[i] = 0;

  ll tot = 0;
  ll prev = -1;
  for(auto m: imos){
    if(prev != -1) ans[tot-1] += (m.first - prev);
    tot += m.second;
    prev = m.first;
  }


  rep(i, n) {
    cout << ans[i] << endl;
  }
}
