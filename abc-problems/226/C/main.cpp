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

ll n;
vector<ll> cost;
vector<ll> G[202020];

int main(){
  cin >> n;
  rep(i, n){
    ll t, k;
    cin >> t >> k;
    cost.push_back(t);
    rep(j, k){
      ll a;
      cin >> a;
      a--;
      G[i].push_back(a);
    }
  }

  ll ans = 0;
  bool seen[202020];
  rep(i, 202020) seen[i] = false;
  queue<ll> que;
  que.push(n-1);
  seen[n-1] = true;

  while(!que.empty()){
    ll idx = que.front();
    que.pop();
    ans += cost[idx];
    for(auto i : G[idx]){
      if(seen[i]) continue;
      seen[i] = true;
      que.push(i);
    }
  }

  cout << ans << endl;
}
