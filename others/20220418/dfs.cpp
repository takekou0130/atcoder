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
vector<pair<int, int> > seen;
vector<vector<int> > G;
int cnt = 0;

void dfs(int v){
  cnt++;
  seen[v].first = cnt;
  for(auto g: G[v]){
    if(seen[g].first == -1){
      dfs(g);
    }
  }
  // 帰りも++するのが重要
  cnt++;
  seen[v].second = cnt;
}

int main(){
  cin >> n;
  rep(i, n){
    pair<int, int> p = {-1, -1};
    seen.push_back(p);
  }
  rep(i, n){
    int u,k;
    cin >> u >> k;
    vector<int> g;
    rep(j, k){
      int in;
      cin >> in;
      g.push_back(--in);
    }
    G.push_back(g);
  }
  rep(i, n){
    if(seen[i].first == -1) dfs(i);
  }
  rep(i, n){
    cout << i + 1 << " " << seen[i].first << " " << seen[i].second << endl;
  }
}
