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
vector<TP> v;
ll tab[202][202];
set<ll> st;
// 訓練がll -> <from to>
map<ll, vector<P> > mp;

int main(){
  cin >> n;
  rep(i, n){
    ll x, y, p;
    cin >> x >> y >> p;
    v.push_back({x, y, p});
  }
  // iからjにいくために必要な訓練
  rep(i, n) rep(j, n){
    if(i == j){
      tab[i][j] = 0;
      continue;
    }
    ll calc = (abs(get<0>(v[i])-get<0>(v[j])) + abs(get<1>(v[i])-get<1>(v[j])) - 1) / get<2>(v[i]) + 1;
    tab[i][j] = calc;
    mp[calc].push_back({i, j});
    st.insert(calc);
  }

  vector<ll> G[202];
  for(auto m: mp){
    for(auto pairs: m.second) {
      G[pairs.first].push_back(pairs.second);
    }

    rep(i, n){
      queue<ll> que;
      ll seen[202];
      rep(i, n) seen[i] = false;
      seen[i] = true;
      que.push(i);
      while(!que.empty()){
        auto now = que.front();
        que.pop();

        for(auto g: G[now]){
          if(seen[g]) continue;
          seen[g] = true;
          que.push(g);
        }
      }
      bool flag = true;
      rep(i, n){
        if(!seen[i]) flag = false;
      }
      if(flag) {
        cout << m.first << endl;
        return 0;
      }
    }
  }
}
