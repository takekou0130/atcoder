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

string s;
char v[7][2];

int main(){
  cin >> s;
  if(s[0] == '1'){
    cout << "No" << endl;
    return 0;
  }

  rep(i, 7) rep(j, 2) v[i][j] = '0';
  v[0][0] = s[6];
  v[1][0] = s[3];
  v[2][0] = s[1];
  v[2][1] = s[7];
  v[3][0] = s[0];
  v[3][1] = s[4];
  v[4][0] = s[2];
  v[4][1] = s[8];
  v[5][0] = s[5];
  v[6][0] = s[9];

  rep(i, 6) {
    rep2(j, i+2, 7){
      bool flag = true;

      if(v[i][0] == '0' && v[i][1] == '0') flag = false;
      if(v[j][0] == '0' && v[j][1] == '0') flag = false;

      rep2(k, i+1, j){
        if(v[k][0] == '1' || v[k][1] == '1') flag = false;
      }

      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
