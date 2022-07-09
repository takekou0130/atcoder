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
int ng[3];
vector<int> G[303];
bool ok = false;

bool check(int num){
  bool flag = true;
  rep(i, 3){
    if(ng[i] == num) flag = false;
  }
  return flag;
}

void bfs(){
  int dist[303];
  rep(i, 303) dist[i] = 1e6;
  queue<int> que;
  que.push(n);
  dist[n] = 0;
  while(!que.empty()){
    int now = que.front();
    que.pop();
    for(auto g : G[now]){
      if(dist[g] > dist[now] + 1){
        dist[g] = dist[now]+1;
        que.push(g);
      }
    }
  }
  if(dist[0] <= 100) ok = true;
}

int main(){
  cin >> n;
  rep(i, 3) cin >> ng[i];
  if(!check(n)){
    cout << "NO" << endl;
    return 0;
  }
  for(int i = n; i > 0; i--){
    for(int j = 1; j <= 3; j++){
      if(!check(i)) continue;
      int next = i - j;
      if (next >= 0 && check(next)){
        G[i].push_back(next);
      }
    }
  }

  bfs();
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}
