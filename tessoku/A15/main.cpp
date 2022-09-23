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
// val,pos;
P a[101010];
int b[101010];

int main(){
  cin >> n;
  rep(i, n) {
    ll val;
    cin >> val;
    a[i] = {val, i};
  }

  sort(a, a+n);
  ll cur = 0;
  rep(i, n) {
    if(i != 0 && a[i-1].first == a[i].first) {
      b[a[i].second] = cur;
    } else {
      cur++;
      b[a[i].second] = cur;
    }
  }

  rep(i, n) {
    cout << b[i];
    if(i != n-1) cout << " ";
  }
  cout << endl;
}
