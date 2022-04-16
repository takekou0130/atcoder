#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int m, n;
int target[201][2];
int star[1001][2];

int main(){
  cin >> m;
  rep(i, m) cin >> target[i][0] >> target[i][1];
  cin >> n;
  rep(i, n) cin >> star[i][0] >> star[i][1];
  int base_x = target[0][0];
  int base_y = target[0][1];
  rep(i, n){
    int diff_x = star[i][0] - base_x;
    int diff_y = star[i][1] - base_y;
    bool flag = true;
    rep2(j, 1, m){
      bool exist = false;
      rep(k, n){
        if(star[k][0] == target[j][0] + diff_x && star[k][1] == target[j][1] + diff_y) exist = true;
      }
      if(!exist){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << diff_x << " " << diff_y << endl;
      return 0;
    }
  }
}
