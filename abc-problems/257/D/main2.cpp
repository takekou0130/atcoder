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
ll x[202], y[202], p[202];

bool root(ll from, ll to, ll s){
  return p[from] * s >= abs(x[from] - x[to]) + abs(y[from] - y[to]);
}

bool check(ll m) {
  rep(i, n){
    set<ll> seen;
    queue<ll> que;

    que.push(i);
    seen.insert(i);

    while(!que.empty()){
      auto now = que.front();
      que.pop();

      rep(j, n){
        if(root(now, j, m) && !seen.count(j)){
          que.push(j);
          seen.insert(j);
        }
      }
    }

    if(seen.size() == n) return true;
  }
  return false;
}

int main(){
  cin >> n;
  rep(i, n) cin >> x[i] >> y[i] >> p[i];

  ll ng = -1LL;
  ll ok = 4000000010LL;
  while(ok - ng > 1){
    ll mid = ng + (ok - ng) / 2LL;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
