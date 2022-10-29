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

int n,m;
vector<int> G[202020];
vector<int> res;
int dist[202020];

int main(){
  cin >> n >> m;
  rep(i, n) {
    dist[i] = 0;
  }
  rep(i, m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    dist[b]++;
  }

  for(auto &g: G){
    sort(g.begin(), g.end());
  }

  priority_queue<int> que;
  rep(i, n){
    if(dist[i] == 0) que.push(i);
  }

  while(!que.empty()){
    int now = que.top();
    que.pop();
    res.push_back(now);
    for(auto g: G[now]){
      dist[g]--;
      if(dist[g] == 0) que.push(g);
    }
  }

  if(n != res.size()) {
    cout << -1 << endl;
    return 0;
  }

  rep(i, n) cout << res[i]+1 << endl;
}
