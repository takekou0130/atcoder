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

int h, w, n;
// 通れればtrue通れなければfalse
bool field[1001][1001];
// startとgoalの座標集
P sg[10];
int ans = 0;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int bfs(P s, P g){
  int dist[1001][1001];
  rep(i, 1001) rep(j, 1001){
    dist[i][j] = -1;
  }
  queue<P> que;

  dist[s.first][s.second] = 0;
  que.push(s);

  while(!que.empty()){
    P now = que.front();
    que.pop();

    rep(i, 4){
      int nx = now.first + dx[i];
      int ny = now.second + dy[i];
      if(dist[nx][ny] != -1 || !field[nx][ny]) continue;

      dist[nx][ny] = dist[now.first][now.second] + 1;
      que.push({nx, ny});
    }
  }

  return dist[g.first][g.second];
}

int main(){
  rep(i, 1001) rep(j, 1001) field[i][j] = false;
  cin >> h >> w >> n;
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) {
      if(s[j] != 'X') {
        field[i][j] = true;
      }

      if(s[j] == 'S') sg[0] = {i, j};
      if(s[j] == '1') sg[1] = {i, j};
      if(s[j] == '2') sg[2] = {i, j};
      if(s[j] == '3') sg[3] = {i, j};
      if(s[j] == '4') sg[4] = {i, j};
      if(s[j] == '5') sg[5] = {i, j};
      if(s[j] == '6') sg[6] = {i, j};
      if(s[j] == '7') sg[7] = {i, j};
      if(s[j] == '8') sg[8] = {i, j};
      if(s[j] == '9') sg[9] = {i, j};
    }
  }

  rep(i, n){
    ans += bfs(sg[i], sg[i+1]);
  }

  cout << ans << endl;
}
