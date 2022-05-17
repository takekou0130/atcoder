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
map<string, P> mp;

int main(){
  cin >> n;

  rep(i, n){
    string s;
    ll t;
    cin >> s >> t;
    P p = {t, i+1};
    mp.insert({s,p});
  }

  ll score = -1;
  for(auto m: mp){
    chmax(score, m.second.first);
  }
  set<ll> s;
  for(auto m: mp){
    if(m.second.first == score) s.insert(m.second.second);
  }
  cout << *s.begin() << endl;
}
