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

int n, k;
vector<ll> h;
int main(){
  cin >> n >> k;
  rep(i, n){
    ll in;
    cin >> in;
    h.push_back(in);
  }

  sort(h.begin(), h.end());
  ll ans = 1e18;
  rep(i, n){
    if(i+k-1 > n-1) continue;
    chmin(ans, h[i+k-1] - h[i]);
  }
  cout << ans << endl;
}
