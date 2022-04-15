#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int r, c;
vector<vector<ll> > s;

int main(){
  cin >> r >> c;
  rep(i, r){
    vector<ll> bit;
    rep(j, c){
      int in;
      cin >> in;
      bit.push_back(in);
    }
    s.push_back(bit);
  }

  ll ans = 0;
  rep(i, pow(2, r)){
    // 1の数をカウントする
    vector<int> eva(c);
    rep(j, r){
      vector<ll> bit = s[j];
      bool is_change = false;
      if(i & 1<<j) is_change = true;
      if(is_change){
        // ひっくり返すとき
        for(int k = c-1; k >= 0; k--){
          if(!bit[k]){
            eva[k]++;
          }
        }
      } else {
        // そのままのとき
        for(int k = c-1; k >= 0; k--){
          if(bit[k]){
            eva[k]++;
          }
        }
      }
    }

    ll res = 0;
    rep(j, c){
      if(eva[j] > (r / 2)){
        res += eva[j];
      } else {
        res += (r - eva[j]);
      }
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
}
