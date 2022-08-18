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

int n,m;
map<ll, int> mp;

int main(){
  cin >> n >> m;
  rep(i, n){
    ll a;
    cin >> a;
    mp[a]++;
  }
  rep(i, m) {
    ll b;
    cin >> b;
    if(mp.count(b) && mp[b] > 0) mp[b]--;
    else {
      cout << "No" << endl;
      return 0;
    }
  };
  cout << "Yes" << endl;
}
