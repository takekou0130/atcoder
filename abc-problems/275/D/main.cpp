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

map<ll, ll> mp;

ll f(ll in){
  if(mp.count(in)) return mp[in];
  if(in == 0) return 1LL;

  ll ans = f(in/2LL) + f(in/3LL);
  mp[in] = ans;
  return ans;
}

int main(){
  ll n;
  cin >> n;
  cout << f(n) << endl;
}
