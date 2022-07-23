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

vector<ll> G[101010];
int n;
int main(){
  int dist[101010];
  queue<int> que;
  // -1で初期化
  rep(i, n) dist[i] = -1;
  // stが始点
  que.push(st);
  dist[st] = 0;
  while(!que.empty()){
    int now = que.front();
    que.pop();

    for(auto g: G[now]){
      if(dist[g] == -1 || dist[g] > dist[now]+1){
        dist[g] = dist[now] + 1;
        que.push(g);
      }
    }
  }
}
