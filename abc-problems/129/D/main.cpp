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
char fd[2020][2020];
int yoko[2020][2020];
int tate[2020][2020];

int main(){
  cin >> h >> w;
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) {
      fd[i][j] = s[j];
    }
  }

  rep(i, h) {
    int len = 0;
    rep(j, w){
      if(fd[i][j] == '.') {
        len++;
        yoko[i][j] = len;
      } else {
        len = 0;
        yoko[i][j] = -1;
      }
    }
  }

  rep(i, h) {
    int past = -1;
    for(int j = w-1; j >= 0; j--){
      if(yoko[i][j] == -1) {
        past = -1;
      } else {
        yoko[i][j] = max(past, yoko[i][j]);
        past = yoko[i][j];
      }
    }
  }

  rep(j, w) {
    int len = 0;
    rep(i, h) {
      if(fd[i][j] == '.') {
        len++;
        tate[i][j] = len;
      } else {
        len = 0;
        tate[i][j] = -1;
      }
    }
  }


  rep(j, w) {
    int past = -1;
    for(int i = h-1; i >= 0; i--){
      if(tate[i][j] == -1) {
        past = -1;
      } else {
        tate[i][j] = max(past, tate[i][j]);
        past = tate[i][j];
      }
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) chmax(ans, tate[i][j] + yoko[i][j] - 1);
  cout << ans << endl;
}
