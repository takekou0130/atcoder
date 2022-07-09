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
char v[10][10];
int tate[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int yoko[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
  cin >> n;
  rep(i, n){
    string in;
    cin >> in;
   rep(j, n) {
      v[i][j] = in[j];
   }
  }
  ll ans = 0;
  rep(i, n) rep(j, n) rep(k, 8) {
    string s = "";
    s += v[i][j];
    int x = j;
    int y = i;
    rep(l, n-1) {
      x = (x + yoko[k] + n ) % n;
      y = (y + tate[k] + n) % n;
      s += v[y][x];
    }
    chmax(ans, stoll(s));
  }
  cout << ans << endl;
}
