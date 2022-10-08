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
char field[32][32];
ll dp[32][32];

int main(){
  cin >> h >> w;
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) field[i][j] = s[j];
  }

  rep(i, 32) rep(j, 32) dp[i][j] = 0;
  dp[0][0] = 1;

  rep(len, h+w-2) {
    rep(i, len+1) {
      int x = i;
      int y = len - i;
      if(0 > x || h <= x || 0 > y || w <= y) continue;
      if(field[x][y] == '#') continue;

      dp[x+1][y] += dp[x][y];
      dp[x][y+1] += dp[x][y];
    }
  }

  rep(i, h) {
    rep(j, w) {
      cout << dp[i][j] << " ";
    }

    cout << endl;
  }

  cout << dp[h-1][w-1] << endl;
}
