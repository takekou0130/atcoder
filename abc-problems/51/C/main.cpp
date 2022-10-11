#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define endl "\n"
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b

// +1000する
int dist[2520][2520];
bool used[2520][2520];
string ans = "";

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int dmap[4] = {'U', 'D', 'L', 'R'};

void bfs(int sx, int sy) {
  queue<P> que;
  dist[sx][sy] = 0;
  que.push({sx,sy});
  while(!que.empty()){
    P now = que.front();
    que.pop();

    rep(i, 4) {
      int nx = now.first+dx[i];
      int ny = now.second+dy[i];
      if(nx < 0 || nx > 2519 || ny < 0 || ny > 2519) continue;
      if(used[nx][ny]) continue;
      if(dist[nx][ny] == -1 || dist[nx][ny] > dist[now.first][now.second]+1){
        dist[nx][ny] = dist[now.first][now.second]+1;
        que.push({nx,ny});
      }
    }
  }
}

void calc(int tx, int ty){
  string tmp = "";
  int crr = dist[tx][ty];
  int nowx = tx;
  int nowy = ty;
  while(crr > 0){
    rep(i, 4) {
      int px = nowx - dx[i];
      int py = nowy - dy[i];
      if(px < 0 || px > 2519 || py < 0 || py > 2519) continue;
      if(dist[px][py] == crr - 1) {
        nowx = px;
        nowy = py;
        used[px][py] = true;
        crr--;
        tmp += dmap[i];
        break;
      }
    }
  }

  for(int i = tmp.size()-1; i >= 0; i--) ans += tmp[i];
}

void reset(int sx, int sy, int tx, int ty){
  rep(i, 2520) rep(j, 2520) dist[i][j] = -1;
  used[sx][sy] = false;
  used[tx][ty] = false;
}

int main(){
  rep(i, 2520) rep(j, 2520) {
    dist[i][j] = -1;
    used[i][j] = false;
  }

  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  sx += 1200;
  sy += 1200;
  tx += 1200;
  ty += 1200;

  bfs(sx,sy);

  calc(tx, ty);

  reset(sx,sy,tx,ty);

  bfs(tx,ty);
  calc(sx,sy);
  reset(sx,sy,tx,ty);
  bfs(sx,sy);
  calc(tx, ty);
  reset(sx,sy,tx,ty);
  bfs(tx,ty);
  calc(sx,sy);
  reset(sx,sy,tx,ty);
  cout << ans << endl;
}
