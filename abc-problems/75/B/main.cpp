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

int yoko[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int tate[8] = {-1, -1, -1, 0, 0 ,1, 1, 1};
int h, w;
int ans[50][50];
char f[50][50];

int main(){
  cin >> h >> w;
  rep(i, 50) rep(j, 50) f[i][j] = 'b';
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w){
      f[i][j] = s[j];
    }
  }

  rep(i, h){
    rep(j, w){
      if(f[i][j] == '#'){
        ans[i][j] = '#';
        continue;
      }
      int res = 0;
      rep(k, 8){
        if(i+yoko[k] < 0 || i+yoko[k] >= h || j+tate[k] < 0 || j+tate[k] >= w) continue;
        if(f[i+yoko[k]][j+tate[k]] == '#') res++;
      }
      ans[i][j] = res;
    }
  }

  rep(i, h){
    rep(j, w){
      if(ans[i][j] == '#') cout << '#';
      else cout << ans[i][j];
    }
    cout << endl;
  }
}
