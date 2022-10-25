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
vector<int> G[402020];
int dist[402020];

int main(){
  cin >> n;
  rep(i, n){
    int a;
    cin >> a;
    int now = i+1;
    G[a].push_back(2 * now);
    G[a].push_back(2 * now + 1);
  }

  rep(i, 402020) dist[i] = -1;
  queue<int> que;
  que.push(1);
  dist[1] = 0;
  while(!que.empty()){
    int now = que.front();
    que.pop();

    for(auto g: G[now]){
      if(dist[g] == -1 || dist[g] > dist[now]+ 1){
        dist[g] = dist[now]+1;
        que.push(g);
      }
    }
  }

  rep2(i, 1, 2 * n +2){
    cout << dist[i] << endl;
  }
}
