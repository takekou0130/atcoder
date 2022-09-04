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

int h,w,k;
ll f_orig[31][31];
ll f[31][31];

// 消す位置を指定してスコアを計算
ll calc(int h_0, int w_0) {
  rep(i,h) rep(j,w) f[i][j] = f_orig[i][j];
  f[h_0][w_0] = 0;
  ll tot = 0;
  ll sco_b = 1;

  while(true){
    // 落とす
    rep(j, w){
      int cnt = 0;
      for(int i = h-1; i >= 0; i--) {
        if(f[i][j] == 0){
          cnt++;
        } else {
          swap(f[i+cnt][j],f[i][j]);
        }
      }
    }


    // 消える判定をする
    ll sco = 0;
    rep(i,h){
      ll past = 0;
      ll pst_idx = -1;

      rep(j, w){
        if(past == f[i][j]){
          // 基本何もしない
          // 端だったときだけ処理
          if(j == w-1 && w-pst_idx >= k){
            sco += past * (w-pst_idx);
            rep2(jj, pst_idx, w) f[i][jj] = 0;
          }
        } else {
          // 切り替わったポイント
          if(j - pst_idx >= k){
            sco += past * (j - pst_idx);
            rep2(jj, pst_idx, j) f[i][jj] = 0;
          }
          past = f[i][j];
          pst_idx = j;
        }
      }
    }

    // 計算する
    if(sco == 0) break;
    tot += sco_b * sco;
    sco_b *= 2;
  }
  return tot;
}

int main(){
  cin >> h >> w >> k;
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w) f_orig[i][j] = s[j] - '0';
  }

  ll ans = 0;
  rep(i, h) rep(j, w) chmax(ans, calc(i,j));
  cout << ans << endl;
}
