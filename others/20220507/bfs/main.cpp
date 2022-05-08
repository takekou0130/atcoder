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

int r, c;
int sx, sy, gx, gy;
char G[51][51];
int dist[51][51];
int xd[4] = {0, -1, 1, 0};
int yd[4] = {-1, 0, 0, 1};

void bfs(){
  queue<P> que;
  dist[sx][sy] = 0;
  que.push({sx, sy});

  while(!que.empty()){
    P now = que.front();
    que.pop();

    rep(i, 4){
      int nx = now.first + xd[i];
      int ny = now.second + yd[i];
      if(dist[nx][ny] != -1 || G[nx][ny] == '#') continue;

      dist[nx][ny] = dist[now.first][now.second] + 1;
      que.push({nx, ny});
    }
  }
}

int main(){
  cin >> r >> c >> sx >> sy >> gx >> gy;
  sx--;
  sy--;
  gx--;
  gy--;
  rep(i, r){
   string s;
   cin >> s;
   rep(j, c){
    G[i][j] = s[j];
  }
  }
  rep(i, 51) rep(j, 51) dist[i][j] = -1;

  bfs();
  cout << dist[gx][gy] << endl;
}
