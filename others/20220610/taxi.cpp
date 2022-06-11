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

ll n,k;
ll c[5050];
ll r[5050];
vector<int> route[5050];
// cost, distination
vector<P> G[5050];

int main(){
  cin >> n >> k;
  rep(i, n) cin >> c[i] >> r[i];
  rep(i,k){
    int a, b;
    cin >> a >> b;
    a--; b--;
    route[a].push_back(b);
    route[b].push_back(a);
  }

  // タクシーのルートのグラフを作る
  rep(i, n){
    vector<int> dist(n, -1);
    queue<int> que;
    que.push(i);
    dist[i] = 0;
    while(!que.empty()){
      auto now = que.front();
      que.pop();
      if(dist[now] >= r[i]) continue;
      for(auto rou: route[now]){
        if(dist[rou] == -1 || dist[rou] > dist[now]+1){
          G[i].push_back({c[i], rou});
          dist[rou] = dist[now]+1;
          que.push(rou);
        }
      }
    }
  }

  // ダイクストラ
  // cost, 位置
  priority_queue<P, vector<P>, greater<P> > que;
  vector<ll> cost(n, -1);
  que.push({0, 0});
  cost[0] = 0;
  while(!que.empty()){
    auto now = que.top();
    que.pop();
    if(cost[now.second] < now.first) continue;
    for(auto g: G[now.second]){
      if(cost[g.second] == -1 || cost[g.second] > cost[now.second] + g.first){
        cost[g.second] = cost[now.second] + g.first;
        que.push({cost[g.second], g.second});
      }
    }
  }

  cout << cost[n-1] << endl;
}
