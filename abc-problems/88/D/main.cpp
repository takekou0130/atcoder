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

int h, w;
bool field[51][51];
int dist[51][51];
int black = 0;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int main(){
  rep(i, 51) rep(j, 51){
    field[i][j] = false;
    dist[i][j] = -1;
  }
  cin >> h >> w;
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w){
      if(s[j] == '.') field[i][j] = true;
      else black++;
    }
  }

  dist[0][0] = 1;
  queue<P> que;
  que.push({0, 0});
  while(!que.empty()){
    P now = que.front();
    que.pop();

    rep(i, 4){
      int nx = now.second + dx[i];
      int ny = now.first + dy[i];
      if(nx < 0 || nx >= w) continue;
      if(ny < 0 || ny >= h) continue;
      if(!field[ny][nx] || dist[ny][nx] != -1) continue;
      dist[ny][nx] = dist[now.first][now.second] + 1;
      que.push({ny, nx});
    }
  }
  if(dist[h-1][w-1] == -1) cout << -1 << endl;
  else cout << h * w - dist[h-1][w-1] - black << endl;
}
