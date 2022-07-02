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
string s;
vector<ll> big;
vector<ll> sma;

int main(){
  cin >> n >> s;
  rep(i, n){
    ll w;
    cin >> w;
    if(s[i] == '0') sma.push_back(w);
    else big.push_back(w);
  }

  sort(sma.begin(), sma.end());
  sort(big.begin(), big.end());
  if(big.size() == 0){
    cout << n << endl;
    return 0;
  }

  ll max_p = 0;
  rep(i, big.size()){
    ll ans = 0;
    ll x = big[i];
    ans += big.size() - i;
    ans += lower_bound(sma.begin(), sma.end(), x) - sma.begin();
    chmax(max_p, ans);
  }
  cout << max_p << endl;
}
