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

int n,m;
bool arr[101][101];

int main(){
  cin >> n >> m;
  rep(i, 101) rep(j, 101) arr[i][j] = false;
  rep(i, m) {
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    arr[u][v] = true;
    arr[v][u] = true;
  }
  ll ans = 0;
  for(int a = 0; a < n; a++){
    for(int b = a+1; b < n; b++){
      for(int c = b+1; c < n; c++){
        if(arr[a][b] && arr[b][c] && arr[c][a]) ans++;
      }
    }
  }
  cout << ans << endl;
}
