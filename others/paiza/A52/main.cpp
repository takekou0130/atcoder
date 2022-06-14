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

int n,a,b;
vector<bool> v;

int main(){
  cin >> n >> a >> b;
  rep(i, n+2) v.push_back(false);
  v[0] = true;
  rep(i, n+1){
    if(!v[i]) continue;
    if(i+a <= n) v[i+a] = true;
    if(i+b <= n) v[i+b] = true;
  }
  v[n] = true;
  int ans = 0;
  rep(i, n+1){
    if(!v[i]) ans++;
  }
  cout << ans << endl;
}
