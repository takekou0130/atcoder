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

int dist[101010];
int n, m;
vector<int> G[101010];

int dfs(int s){
  int res = -1;
  for(auto g: G[s]){
    if(dist[g] != -1) chmax(res, dist[g]);
    else chmax(res, dfs(g));
  }
  res++;
  dist[s] = res;
  return res;
}

int main(){
  cin >> n >> m;
  rep(i, m){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
  }

  rep(i, n) {
    dist[i] = -1;
  }

  rep(i, n){
    if(dist[i] != -1) continue;
    dfs(i);
  }

  int ans = -1;
  rep(i, n) chmax(ans, dist[i]);
  cout << ans << endl;
}
