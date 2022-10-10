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

ll n,m;
vector<P> mv;
ll fld[404][404];

bool is_squere(ll N) {
    ll r = (ll)floor(sqrt((ld)N));  // 切り捨てした平方根
    return (r * r) == N;
}

int main(){
  cin >> n >> m;

  rep(k, m+1){
    ll l2 = m - k * k;
    if(l2 >= 0 && is_squere(l2)){
      ll l = (ll)floor(sqrt((ld)l2));
      if(k == 0) {
        mv.push_back({k, l});
        mv.push_back({k, -l});
      } else if (l == 0) {
        mv.push_back({k,l});
        mv.push_back({-k,l});
      } else {
        mv.push_back({k,l});
        mv.push_back({k,-l});
        mv.push_back({-k,l});
        mv.push_back({-k,-l});
      }
    }
  }

  rep(i, 404) rep(j, 404) fld[i][j] = -1;
  fld[0][0] = 0;

  queue<P> que;
  que.push({0,0});
  while(!que.empty()){
    P now = que.front();
    que.pop();

    for(P now_mv: mv) {
      ll nx_y = now.first + now_mv.first;
      ll nx_x = now.second + now_mv.second;
      if(nx_y < 0 || nx_y >= n || nx_x < 0 || nx_x >= n) continue;
      if(fld[nx_y][nx_x] == -1 || fld[nx_y][nx_x] > fld[now.first][now.second]+1) {
        fld[nx_y][nx_x] = fld[now.first][now.second] + 1;
        que.push({nx_y,nx_x});
      }
    }
  }

  rep(i, n) {
    rep(j, n) {
      cout << fld[i][j];
      if(j != n-1) cout << " ";
    }
    cout << endl;
  }
}
