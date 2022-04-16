#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> TP;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define endl "\n"
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b

int k;
int need[8];
int p[8];


int main(){
  cin >> k;
  rep(i, 8){
    need[i] = -1;
    p[i] = i;
  }

  rep(i, k){
    int r, c;
    cin >> r >> c;
    need[r] = c;
  }

  do {
    int bord[8][8];
    // 0 -> なんもない
    // -1 -> ななめ攻撃範囲
    // 1 -> 駒あり
    rep(i, 8) rep(j, 8) bord[i][j] = 0;

    bool flag = true;
    rep(i, 8){
      // コマを置く場所が指定されているとき
      if(need[i] != -1){
        // 置き場所と指定があってなかったらout
        if(need[i] != p[i]){
          flag = false;
          break;
        }

        // 置き場所があっていたらななめチェック
        if(bord[i][need[i]] == -1){
          flag = false;
          break;
        }
        // コマを置く
        bord[i][need[i]] == 1;
        // ななめフラグを立てつつ他を攻撃してないかチェック
        rep(j, 8) {
          int dif = abs(i - j);
          if(dif == 0) continue;
          // 左側
          if(need[i] - dif >= 0){
            if(bord[j][need[i] - dif] == 1){
              flag = false;
              break;
            }
            bord[j][need[i] -dif] = -1;
          }
          // 右側
          if(need[i] + dif <= 7){
            if(bord[j][need[i] + dif] == 1){
              flag = false;
              break;
            }
            bord[j][need[i] + dif] = -1;
          }
        }
      // 指定されていないとき
      } else {
         // ななめチェック
        if(bord[i][p[i]] == -1){
          flag = false;
          break;
        }
        // コマを置く
        bord[i][p[i]] == 1;
        // ななめフラグを立てつつ他を攻撃してないかチェック
        rep(j, 8) {
          int dif = abs(i - j);
          if(dif == 0) continue;
          // 左側
          if(p[i] - dif >= 0){
            if(bord[j][p[i] - dif] == 1){
              flag = false;
              break;
            }
            bord[j][p[i] -dif] = -1;
          }
          // 右側
          if(p[i] + dif <= 7){
            if(bord[j][p[i] + dif] == 1){
              flag = false;
              break;
            }
            bord[j][p[i] + dif] = -1;
          }
        }
      }
    }

    if (flag){
      break;
    }
  } while(next_permutation(p, p+8));
  rep(i, 8){
    string base = "........";
    base[p[i]] = 'Q';
    cout << base << endl;
  }
}
