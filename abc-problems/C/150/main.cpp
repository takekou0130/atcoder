#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;

int main(){
  cin >> n;
  vector<vector<int> > v(2, vector<int>(n, 0));
  rep(i, 2) rep(j, n) cin >> v[i][j];
  vector<int> ord(n);
  rep(i, n) ord[i] = i+1;
  int cnt = 1;
  int a, b;
  do {
    vector<bool> flag = {true, true};
    rep(i, 2) rep(j, n){
      if(v[i][j] != ord[j]) flag[i] = false;
    }
    if (flag[0]) a = cnt;
    if (flag[1]) b = cnt;
    cnt++;
  } while(next_permutation(ord.begin(), ord.end()));
  cout << abs(a-b) << endl;
}
