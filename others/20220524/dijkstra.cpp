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

// cost, to
vector<P> G[100100];
ll v, e, r;
ll dist[100100];
ll inf = 1e18;

int main(){
  cin >> v >> e >> r;
  rep(i, e){
    ll s,t,d;
    cin >> s >> t >> d;
    G[s].push_back({d, t});
  }

  rep(i, v) dist[i] = inf;
  priority_queue<P, vector<P>, greater<P> > que;
  que.push({0, r});
  dist[r] = 0;
  while(!que.empty()){
    auto now = que.top();
    que.pop();
    if(dist[now.second] < now.first) continue;
    for(auto g: G[now.second]){
      if(dist[g.second] > dist[now.second] + g.first){
        dist[g.second] = dist[now.second] + g.first;
        que.push({dist[g.second], g.second});
      }
    }
  }

  rep(i, v){
    if(dist[i] == inf) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }
}
