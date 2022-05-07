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

int n, q;
vector<int> G[202020];
ll ans[202020] = {0};
bool seen[202020];

void dfs(int s, ll par){
  ans[s] += par;
  seen[s] = true;
  for(auto g: G[s]){
    if(seen[g]) continue;
    dfs(g, ans[s]);
  }
}

int main(){
  cin >> n >> q;
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
    seen[i] = false;
  }

  rep(i, q){
    int p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }

  dfs(0, 0);

  rep(i, n){
    if(i == n-1) cout << ans[i] << endl;
    else cout << ans[i] << " ";
  }
}
