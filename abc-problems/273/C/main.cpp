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
ll a[202020];
map<ll, ll> mp;
vector<ll> ans;

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) {
    mp[a[i]]++;
  }

  for(auto m: mp){
    ans.push_back(m.second);
  }
  reverse(ans.begin(), ans.end());
  rep(i, n){
    if(i >= ans.size()) cout << 0 << endl;
    else cout << ans[i] << endl;
  }
}
