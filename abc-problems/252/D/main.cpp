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
int arr[202020];
map<int, vector<int> > mp;

int main(){
  cin >> n;
  rep(i, n) cin >> arr[i];
  rep(i, n){
    mp[arr[i]].push_back(i);
  }
  ll ans = 0;
  rep2(j, 1, n-1){
    int idx = lower_bound(mp[arr[j]].begin(), mp[arr[j]].end(), j) - mp[arr[j]].begin();
    ll lef = (ll)idx;
    ll rig = (ll)mp[arr[j]].size() - (ll)idx - 1LL;
    ans += (ll)(j) * (ll)(n-j-1) - lef * (ll)(n-j-1) - rig * (ll)(j) + lef * rig;
    cout << ans << endl;
  }

  cout << ans << endl;
}
