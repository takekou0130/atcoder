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

int H,W,h,w;
char arr[21][21];

int main(){
  cin >> H >> W >> h >> w;
  rep(i, 21) rep(j, 21) arr[i][j] = 'u';
  rep(i, H) rep(j, W) arr[i][j] = 'w';
  rep(i, h) rep(j, 21) arr[i][j] = 'b';
  rep(i, 21) rep(j, w) arr[i][j] = 'b';
  int ans = 0;
  rep(i, H) rep(j, W) {
    if(arr[i][j] == 'w') ans++;
  }
  cout << ans << endl;
}
