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

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int main(){
  while(true){
    int w,h;
    cin >> w >> h;
    if(w == 0 && h == 0) return 0;

    int border[60][31];
    rep(i, 2*h-1){
      if(i%2 == 0) {
        rep(j, w-1){
          cin >> border[i][j];
        }
      } else {
        rep(j, w){
          cin >> border[i][j];
        }
      }
    }

    int field[31][31];
    rep(i, 31) rep(j, 31) field[i][j] = -1;

    queue<P> que;
    field[0][0] = 0;
    que.push({0, 0});
    while(!que.empty()){
      P now = que.front();
      que.pop();

      rep(i, 4){
        int nx = now.second + dx[i];
        int ny = now.first + dy[i];
        if(nx < 0 || nx >= w) continue;
        if(ny < 0 || ny >= h) continue;
        if(field[ny][nx] != -1) continue;
        // 上
        if(i == 0){
          if(border[2*now.first - 1][nx] == 0){
            field[ny][nx] = field[now.first][now.second] + 1;
            que.push({ny, nx});
          }
        }

        // 左
        if(i == 1){
          if(border[ny*2][nx] == 0){
            field[ny][nx] = field[now.first][now.second] + 1;
            que.push({ny, nx});
          }
        }

        // 右
        if(i == 2){
          if(border[ny*2][now.second] == 0){
            field[ny][nx] = field[now.first][now.second] + 1;
            que.push({ny, nx});
          }
        }

        // 下
        if(i == 3){
          if(border[2*now.first + 1][nx] == 0){
            field[ny][nx] = field[now.first][now.second] + 1;
            que.push({ny, nx});
          }
        }
      }
    }

    if(field[--h][--w] == -1) cout << 0 << endl;
    else cout << field[h][w] + 1 << endl;
  }
}
