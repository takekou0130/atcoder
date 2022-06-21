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
// to, cost
vector<P> G[202020];
bool seen[202020];
int x[202020];
ll c[202020];
ll ans = 0;
int main(){
  cin >> n;
  rep(i, n) cin >> x[i];
  rep(i, n) cin >> c[i];

  rep(i, n){
    int to = x[i];
    int from = i;
    to--;
    G[from].push_back({to, c[i]});
  }

  rep(i, n) seen[i] = false;
  rep(i, n){
    int start = i;
    if(seen[i]) continue;

    queue<int> que;
    seen[start] = true;
    que.push(start);
    set<int> st;
    priority_queue<int, vector<int>, greater<int>> pst;
    bool flag = false;
    while(!que.empty()){
      auto now = que.front();
      que.pop();

      for(auto g: G[now]){
          pst.push(g.second);
        if(st.count(g.first)){
          flag = true;
        }

        if(!seen[g.first]) {
          seen[g.first] = true;
          pst.push(g.second);
          st.insert(g.first);
          que.push(g.first);
        }
      }
    }
    if(flag) ans += pst.top();
  }

  cout << ans << endl;
}
