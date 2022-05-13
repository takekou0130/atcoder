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

int n, m;
map<ll, ll> mp;
set<ll> v;
ll ans = 0;

int main(){
  cin >> n >> m;
  rep(i, n){
    ll a, b;
    cin >> a >> b;
    v.insert(a);
    mp[a] += b;
  }
  auto itr = v.begin();
  rep(i, m){
    ans += *itr;
    mp[*itr]--;
    if(mp[*itr] == 0) itr++;
  }
  cout << ans << endl;
}
