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

// 出発 目的 距離
map<int, map<int, ll> > G;
ll n,k;

int main(){
  cin >> n >> k;
  rep(i, k){
    int s;
    cin >> s;
    if(s == 0){
      ll a,b;
      cin >> a >> b;
      a--; b--;
      ll dist[n];
      rep(j, n) dist[j] = -1;
      priority_queue<P, vector<P>, greater<P> > que;
      que.push({0, a});
      dist[a] = 0;
      while(!que.empty()){
        auto now = que.top();
        que.pop();
        if(dist[now.second] < now.first) continue;
        for(auto g: G[now.second]){
          if(dist[g.first] == -1 || dist[g.first] > now.first + g.second){
            dist[g.first] = now.first + g.second;
            que.push({dist[g.first], g.first});
          }
        }
      }
      cout << dist[b] << endl;
    }

    if(s == 1){
      ll c, d, e;
      cin >> c >> d >> e;
      c--; d--;
      if(!G[c].count(d)|| G[c][d] > e){
        G[c][d] = e;
        G[d][c] = e;
      }
    }
  }
}
