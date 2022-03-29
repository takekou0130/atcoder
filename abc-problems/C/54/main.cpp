#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n, m;

int main(){
  cin >> n >> m;
  if (m == 0){
    cout << 0 << endl;
    return 0;
  }
  vector<vector<int> > v(m, vector<int>(2,0));
  rep(i, m) rep(j, 2) cin >> v[i][j];
  vector<int> ord(n-1);
  // ord = [2, 3, 4, 5 ... n+1]
  // 最初が1じゃないといけないのでめんどくさい実装になっているが、
  // 1も含めてまわし最後のcnt++のところでord[0] == 1の判定を入れても良さそう
  rep2(i, 1, n) ord[i-1] = i+1;
  int cnt = 0;
  do {
    bool flag = true;
    rep(i, n-1){
      int a,b;
      if(i == 0){
        a = 1;
      } else {
        a = ord[i-1];
      }
      b = ord[i];

      rep(j, m){
        // 無向グラフなのでa->b, b->aのどちらでもOK
        if(a == v[j][0] && b == v[j][1]) break;
        if(a == v[j][1] && b == v[j][0]) break;
        if(j == m-1) flag = false;
      }
    }

    if(flag) cnt++;
  } while(next_permutation(ord.begin(), ord.end()));
  cout << cnt << endl;
}
