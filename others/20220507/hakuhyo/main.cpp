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

int m, n;
int f[91][91] = {0};
ll ans = 0;
int x_d[4] = {0, -1, 1, 0};
int y_d[4] = {-1, 0, 0, 1};

void dfs(int y, int x, bool(&seen)[91][91], ll len){
  len++;
  chmax(ans, len);
  seen[y][x] = true;
  rep(i, 4){
    int next_y = y + y_d[i];
    int next_x = x + x_d[i];
    if(next_y < 0 || next_y >= n) continue;
    if(next_x < 0 || next_x >= m) continue;
    if(seen[next_y][next_x] || f[next_y][next_x] == 0) continue;
    dfs(next_y, next_x, seen, len);
    // 割った氷をもとに戻しておく必要がある
    seen[next_y][next_x] = false;
  }
}

int main(){
  cin >> m >> n;
  rep(i, n) rep(j, m) {
    cin >> f[i][j];
  }
  rep(i, n) rep(j, m) {
    if(!f[i][j]) continue;
    bool seen[91][91];
    rep(k, 91) rep(l, 91) {
      seen[k][l] = false;
    }
    ll len = 0;
    dfs(i, j, seen, len);
  }

  cout << ans << endl;
}
