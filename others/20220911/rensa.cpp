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

int h;
int fld[10][5];

void solv(int h){
  rep(i, 10) rep(j, 5) fld[i][j] = 0;
  rep(i, h) rep(j, 5) cin >> fld[i][j];

  ll ans = 0;
  while(true){

    int cur = 0;
    // 消して計算
    rep(i, h){
      int prev = -1;
      int len = 0;
      int st = 0;
      rep(j, 5){
        if(fld[i][j] == prev){
          len++;
        } else {
          if(len >= 3){
            break;
          } else {
            prev = fld[i][j];
            len = 1;
            st = j;
          }
        }
      }

      // 消しつつ足す
      if(len < 3) continue;
      rep2(j, st, st+len){
        fld[i][j] = 0;
      }
        cur += len*prev;
    }
    // 点数変わらなかったら終了
    if(cur == 0) break;
    ans += cur;


    // 落とす
    rep(j, 5){
      int foo = 0;
      for(int i = h-1; i >= 0; i--){
        if(fld[i][j] == 0) foo++;
        else {
          fld[i+foo][j] = fld[i][j];
          if(foo > 0)fld[i][j] = 0;
        }
      }
    }
  }

  cout << ans << endl;
}

int main(){
  while(true){
    cin >> h;
    if(h == 0) break;
    solv(h);
  }
}
