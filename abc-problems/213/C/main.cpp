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

ll h, w, n;
vector<P> v;
vector<ll> a;
vector<ll> b;

int main(){
  cin >> h >> w >> n;
  rep(i, n){
    ll a_i, b_i;
    cin >> a_i >> b_i;
    pair<ll, ll> tmp;
    tmp.first = a_i;
    tmp.second = b_i;
    v.push_back(tmp);
    a.push_back(a_i);
    b.push_back(b_i);
  }

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  rep(i, n){
    cout << lower_bound(a.begin(), a.end(), v[i].first) - a.begin() + 1 << " " << lower_bound(b.begin(), b.end(), v[i].second) - b.begin() + 1 << endl;
  }
}
