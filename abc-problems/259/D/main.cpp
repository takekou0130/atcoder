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
ll s_x,s_y,t_x,t_y;
ll x[3030], y[3030], r[3030];
vector<ll> G[3030];
int dist[3030];

// 重なるかチェック
bool check(int i, int j){
  ld x_i = (ld)x[i];
  ld x_j = (ld)x[j];
  ld y_i = (ld)y[i];
  ld y_j = (ld)y[j];
  ld r_i = (ld)r[i];
  ld r_j = (ld)r[j];
  ld dd = sqrtl((x_i - x_j)*(x_i - x_j) + (y_i - y_j)*(y_i - y_j));
  if(dd == r_i+r_j) return true;
  if(dd + r_i == r_j) return true;
  if(dd + r_j == r_i) return true;
  if(abs(r_i-r_j) < dd && dd < r_i+r_j) return true;
  return false;
}

int main(){
  cin >> n >> s_x >> s_y >> t_x >> t_y;
  rep(i, n) cin >> x[i]  >> y[i] >> r[i];
  rep(i, n) rep2(j, i+1, n) {
    if(check(i, j)){
      G[i].push_back(j);
      G[j].push_back(i);
    }
  }

  int st_i = -1;
  int go_i = -1;
  rep(i, n) {
    if(st_i == -1 && (s_x-x[i])*(s_x-x[i])+(s_y-y[i])*(s_y-y[i]) == r[i]*r[i]) st_i = i;
    if(go_i == -1 && (t_x-x[i])*(t_x-x[i])+(t_y-y[i])*(t_y-y[i]) == r[i]*r[i]) go_i = i;
  }

  queue<int> que;
  rep(i, n) dist[i] = -1;
  que.push(st_i);
  dist[st_i] = 0;
  while(!que.empty()){
    int now = que.front();
    que.pop();

    for(auto g: G[now]){
      if(dist[g] == -1 || dist[g] > dist[now]+1){
        dist[g] = dist[now] + 1;
        que.push(g);
      }
    }
  }

  if(dist[go_i] != -1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
