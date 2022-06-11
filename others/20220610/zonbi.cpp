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

ll n,m,k,s,p,q;
set<ll> st;
vector<ll> G[101010];
// -1->普通 0->通れない 1以上->高い
int F[101010];
ll inf = 1e18;

int main(){
  cin >> n >> m >> k >> s >> p >> q;
  rep(i, n) F[i] = -1;
  rep(i, k){
    ll in;
    cin >> in;
    in--;
    st.insert(in);
  }

  rep(i, m){
    ll a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  // 高いところをマークする
  for(auto itr = st.begin(); itr != st.end(); itr++){
    queue<int> que;
    que.push(*itr);
    F[*itr] = 0;
    while(!que.empty()){
      auto now = que.front();
      que.pop();
      for(auto g: G[now]){
        if(F[now]+1 > s) continue;
        if(F[g] == -1 || F[g] > F[now]+1){
          F[g] = F[now]+1;
          que.push(g);
        }
      }
    }
  }

  // ダイクストラ
  // コスト, 位置
  priority_queue<P, vector<P>, greater<P> > pque;
  vector<ll> cost(n, inf);
  pque.push({0, 0});
  cost[0] = 0;
  while(!pque.empty()){
    auto now = pque.top();
    pque.pop();
    if(now.first > cost[now.second]) continue;
    for(auto g: G[now.second]){
      // いけない
      if(F[g] == 0) continue;
      // やすくいける
      if(F[g] == -1){
        if(cost[now.second] + p < cost[g]){
          cost[g] = cost[now.second] + p;
          pque.push({cost[g], g});
        }
      } else {
        // 高くいける
        if(cost[now.second]+q < cost[g]){
          cost[g] = cost[now.second] + q;
          pque.push({cost[g], g});
        }
      }
    }
  }

  ll ans = 0;
  if(F[n-1] == -1) ans = cost[n-1] - p;
  else ans = cost[n-1] - q;
  cout << ans << endl;
}
