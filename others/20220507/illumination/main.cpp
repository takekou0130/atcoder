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

int h,w;
bool field[102][102];
int result[102][102];

// yが偶数のときのxの変化量
int dxg[6] = {-1, 0, -1, 1, -1, 0};
// yが奇数のときのxの変化量
int dxk[6] = {0, 1, -1, 1, 0, 1};

int dy[6] = {-1, -1, 0, 0, 1, 1};


void bfs(){
  queue<P> que;
  result[0][0] = 1;
  que.push({0, 0});

  while(!que.empty()){
    P now = que.front();
    que.pop();

    rep(i, 6){
      int nx = now.first;
      if (now.second % 2 == 0) nx += dxg[i];
      else nx += dxk[i];
      int ny = now.second + dy[i];

      if(nx < 0 || nx > 101) continue;
      if(ny < 0 || ny > 101) continue;
      if(result[nx][ny] != -1) continue;
      if(field[nx][ny]) continue;

      result[nx][ny] = 1;
      que.push({nx, ny});
    }
  }
}

int calc() {
  int ans = 0;
  rep(i, 102) rep(j, 102) {
    if(result[i][j] != 1) continue;

    rep(k, 6){
      int nx = i;
      if (j % 2 == 0) nx += dxg[k];
      else nx += dxk[k];
      int ny = j + dy[k];

      if(nx < 0 || nx > 101) continue;
      if(ny < 0 || ny > 101) continue;

      if(field[nx][ny]){
        ans++;
      }
    }
  }
  return ans;
}

int main(){
  cin >> w >> h;
  rep(i, 102) rep(j, 102) field[j][i] = false;
  rep2(i, 1, h+1) rep2(j, 1, w+1){
    int v;
    cin >> v;
    if (v) field[j][i] = true;
    else field[j][i] = false;
  }

  rep(i, 102) rep(j, 102) result[i][j] = -1;
  bfs();
  cout << calc() << endl;
}
