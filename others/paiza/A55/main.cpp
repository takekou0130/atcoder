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
char field[101][101];
P start;
int h_def[4] = {-1, 0,0,1};
int w_def[4] = {0,-1,1,0};
int dist[101][101];
int inf = 1e6;

int main(){
  cin >> h >> w;
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w){
      field[i][j] = s[j];
      if(s[j] == 'S') start = {i,j};
    }
  }

  queue<P> que;
  rep(i,101) rep(j, 101) dist[i][j] = inf;
  que.push(start);
  dist[start.first][start.second] = 0;
  while(!que.empty()){
    auto now = que.front();
    que.pop();
    rep(i, 4){
      int nex_h = now.first+h_def[i];
      int nex_w = now.second+w_def[i];
      // 端見るの忘れてた
      if(field[nex_h][nex_w] != '#' && dist[now.first][now.second] + 1 < dist[nex_h][nex_w]){
        dist[nex_h][nex_w] =  dist[now.first][now.second] + 1;
        que.push({nex_h,nex_w});
      }
    }
  }

  bool flag = false;
  rep(j, w){
    if(dist[0][j] != inf) flag = true;
    if(dist[h-1][j] != inf) flag = true;
  }
  rep(i, h){
    if(dist[i][0] != inf) flag = true;
    if(dist[i][w-1] != inf) flag = true;
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}
