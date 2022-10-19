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

ll a,n;
int inf = 1e9;
ll dist[10101010];
queue<ll> que;

ll cha(ll n) {
  string s = to_string(n);
  string ns = "";
  ns += s[s.size()-1];
  rep(i, s.size()-1) ns += s[i];
  return stoll(ns);
}

int main(){
  cin >> a >> n;

  rep(i, 10101010) dist[i] = -1;

  que.push(1);
  dist[1] = 0;
  while(!que.empty()) {
    auto now = que.front();
    que.pop();

    if(now * a < 1e7 && (dist[now*a] == -1 || dist[now*a] > dist[now]+1)) {
      dist[now*a] = dist[now] + 1;
      que.push(now*a);
    }

    if(now >= 10 && now%10 != 0) {
      ll changed = cha(now);
      if(changed < 10101010 && (dist[changed] == -1 || dist[changed] > dist[now] + 1)){
        dist[changed] = dist[now] + 1;
        que.push(changed);
      }
    }
  }

  cout << dist[n] << endl;
}
