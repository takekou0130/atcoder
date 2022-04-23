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
vector<P> v;

// bool check(ll score){
//   set<int> sec;
//   rep(i, n) sec.insert(i);
//   rep(i, n){
//     if (score - v[i].first < 0) return false;
//     auto itr = upper_bound(sec.begin(), sec.end(), (score - v[i].first) / v[i].second);
//     if(itr == sec.begin()) return false;
//     sec.erase(*(--itr));
//   }
//   return true;
// }

 bool check(ll score){
  vector<ll> sec;
  rep(i, n){
    if (score - v[i].first < 0) return false;
    sec.push_back((score - v[i].first) / v[i].second);
  }
  sort(sec.begin(), sec.end());
  rep(i, n){
    if(sec[i] < i) return false;
  }
  return true;
}

int main(){
  cin >> n;
  rep(i, n){
    P p;
    cin >> p.first >> p.second;
    v.push_back(p);
  }
  ll ok = 2e14;
  ll ng = 0;
  while(ok - ng > 1){
    ll mid = ng + (ok - ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
