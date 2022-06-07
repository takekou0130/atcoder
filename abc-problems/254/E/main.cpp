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

vector<int> G[151515];
int n, m ,q;
set<int> st;
ll ans;

int main(){
  cin >> n >> m;
  rep(i, m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cin >> q;
  rep(i, q){
    int x,k;
    cin >> x >> k;
    x--;
    st.clear();
    ans = 0;
    queue<P> que;
    que.push({x, 0});
    st.insert(x+1);
    while(!que.empty()){
      auto now = que.front();
      que.pop();

      for(auto g: G[now.first]){
        if(!st.count(g+1) && now.second+1 <= k){
          st.insert(g+1);
          que.push({g, now.second+1});
        }
      }
    }

    for(auto itr = st.begin(); itr != st.end(); itr++){
      ans += *itr;
    }
    cout << ans << endl;
  }
}
