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
char fs[202][202], ft[202][202];
P skado[4], tkado[4];
char snuki[202][202], tnuki[202][202];

int main(){
  cin >> n;
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, n) {
      fs[i][j] = s[j];
    }
  }

  rep(i, n) {
    string s;
    cin >> s;
    rep(j, n) ft[i][j] = s[j];
  }

  int lef = n-1;
  int rig = 0;
  int top = n-1;
  int bot = 0;
  rep(i, n) {
    rep(j, n) {
      if(fs[i][j] == '#') {
        chmin(lef, j);
        chmax(rig, j);
        chmin(top, i);
        chmax(bot, i);
      }
    }
  }

  skado[0] = {top, lef};
  skado[1] = {top, rig};
  skado[2] = {bot, rig};
  skado[3] = {bot, lef};
  int syoko = skado[1].second - skado[0].second + 1;
  int state = skado[2].first - skado[1].first + 1;

  rep(i, state) {
    rep(j, syoko) snuki[i][j] = fs[top+i][lef+j];
  }

  lef = n-1;
  rig = 0;
  top = n-1;
  bot = 0;
  rep(i, n) {
    rep(j, n) {
      if(ft[i][j] == '#') {
        chmin(lef, j);
        chmax(rig, j);
        chmin(top, i);
        chmax(bot, i);
      }
    }
  }

  tkado[0] = {top, lef};
  tkado[1] = {top, rig};
  tkado[2] = {bot, rig};
  tkado[3] = {bot, lef};
  int tyoko = tkado[1].second -tkado[0].second + 1;
  int ttate = tkado[2].first - tkado[1].first + 1;

  rep(i, ttate) {
    rep(j, tyoko) tnuki[i][j] = ft[top+i][lef+j];
  }

  // 正方形
  if(syoko == tyoko && state == ttate && tyoko == ttate) {
    // そのまま
    bool flag = true;
    rep(i, ttate) {
      rep(j, tyoko) {
        if(snuki[i][j] != tnuki[i][j]) flag = false;
      }
    }

    if(flag){
       cout << "Yes" << endl;
       return 0;
    }
    // 90
    flag = true;
    rep(i, ttate) {
      rep(j, tyoko) {
        if(snuki[i][j] != tnuki[j][tyoko-i-1]) flag = false;
      }
    }

    if(flag){
       cout << "Yes" << endl;
       return 0;
    }
    // 180
    flag = true;
    rep(i, ttate) {
      rep(j, tyoko) {
        if(snuki[i][j] != tnuki[ttate-i-1][tyoko-j-1]) flag = false;
      }
    }

    if(flag){
       cout << "Yes" << endl;
       return 0;
    }

    // 270
    flag = true;
    rep(i, ttate) {
      rep(j, tyoko) {
        if(snuki[i][j] != tnuki[ttate-j-1][i]) flag = false;
      }
    }

    if(flag){
       cout << "Yes" << endl;
       return 0;
    }
  }
  // そのままの向きで一致
  else if(syoko == tyoko && state == ttate){
    // そのまま
    bool flag = true;
    rep(i, ttate) {
      rep(j, tyoko) {
        if(snuki[i][j] != tnuki[i][j]) flag = false;
      }
    }

    if(flag){
       cout << "Yes" << endl;
       return 0;
    }

    // 180
    flag = true;
    rep(i, ttate) {
      rep(j, tyoko) {
        if(snuki[i][j] != tnuki[ttate-i-1][tyoko-j-1]) flag = false;
      }
    }

    if(flag){
       cout << "Yes" << endl;
       return 0;
    }

  }
  // 90度回転で一致
  else if(syoko == ttate && state == tyoko){
    // 90
    bool flag = true;
    rep(i, ttate) {
      rep(j, tyoko) {
        if(snuki[i][j] != tnuki[j][tyoko-i-1]) flag = false;
      }
    }

    if(flag){
       cout << "Yes" << endl;
       return 0;
    }
    // 270
    flag = true;
    rep(i, ttate) {
      rep(j, tyoko) {
        if(snuki[i][j] != tnuki[ttate-j-1][i]) flag = false;
      }
    }

    if(flag){
       cout << "Yes" << endl;
       return 0;
    }
  }

  // それ以外
  cout << "No" << endl;
}
