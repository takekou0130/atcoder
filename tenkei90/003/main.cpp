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
vector<int> G[101010];
int dist[101010];

int main(){
  cin >> n;
  rep(i, n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep(i, n) dist[i] = -1;

  queue<int> que;
  dist[0] = 0;
  que.push(0);
  while(!que.empty()){
    int now = que.front();
    que.pop();

    for(auto g: G[now]){
      if(dist[g] == -1 || dist[g] > dist[now]+1){
        dist[g] = dist[now]+1;
        que.push(g);
      }
    }
  }

  int haji = 0;
  int mx = 0;
  rep(i, n){
    if(mx < dist[i]){
      haji = i;
      mx = dist[i];
    }
  }

  rep(i, n) dist[i] = -1;

  queue<int> que2;
  dist[haji] = 0;
  que2.push(haji);
  while(!que2.empty()){
    int now = que2.front();
    que2.pop();

    for(auto g: G[now]){
      if(dist[g] == -1 || dist[g] > dist[now]+1){
        dist[g] = dist[now]+1;
        que2.push(g);
      }
    }
  }

  mx = 0;
  rep(i, n){
    chmax(mx, dist[i]);
  }
  cout << mx + 1 << endl;
}
