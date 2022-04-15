#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
string arr[101][2];

int main(){
  cin >> n;
  rep(i, n) cin >> arr[i][0] >> arr[i][1];
  bool flag = true;
  rep(i, n){
    string s = arr[i][0];
    string t = arr[i][1];
    bool flag_s = false;
    bool flag_t = false;
    rep(j, n){
      if(j == i) continue;
      if(s == arr[j][0] || s == arr[j][1]) flag_s = true;
      if(t == arr[j][0] || t == arr[j][1]) flag_t = true;
    }
    if(flag_s && flag_t){
      flag = false;
      break;
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
