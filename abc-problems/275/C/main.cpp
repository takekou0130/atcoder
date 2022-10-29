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

char fi[9][9];

bool f(char c){
  if(c == '#') return true;
  return false;
}

int main(){
  ll ans = 0;
  rep(i, 9){
    string s;
    cin >> s;
    rep(j, 9){
      fi[i][j] = s[j];
    }
  }

  // 2
  rep(i, 8) {
    rep(j, 8){
      if(f(fi[i][j])&& f(fi[i+1][j]) && f(fi[i][j+1]) && f(fi[i+1][j+1])) ans++;
    }
  }

  // 3
  rep(i, 7) {
    rep(j, 7){
      if(f(fi[i][j])&& f(fi[i+2][j]) && f(fi[i][j+2]) && f(fi[i+2][j+2])) ans++;
    }
  }

  // 4
  rep(i, 6) {
    rep(j, 6){
      if(f(fi[i][j])&& f(fi[i+3][j]) && f(fi[i][j+3]) && f(fi[i+3][j+3])) ans++;
    }
  }

  // 5
  rep(i, 5) {
    rep(j, 5){
      if(f(fi[i][j])&& f(fi[i+4][j]) && f(fi[i][j+4]) && f(fi[i+4][j+4])) ans++;
    }
  }

  // 6
  rep(i, 4) {
    rep(j, 4){
      if(f(fi[i][j])&& f(fi[i+5][j]) && f(fi[i][j+5]) && f(fi[i+5][j+5])) ans++;
    }
  }

  // 7
  rep(i, 3) {
    rep(j, 3){
      if(f(fi[i][j])&& f(fi[i+6][j]) && f(fi[i][j+6]) && f(fi[i+6][j+6])) ans++;
    }
  }

  // 8
  rep(i, 2) {
    rep(j, 2){
      if(f(fi[i][j])&& f(fi[i+7][j]) && f(fi[i][j+7]) && f(fi[i+7][j+7])) ans++;
    }
  }

  // 9
  if(f(fi[0][0])&& f(fi[0][8]) && f(fi[8][0]) && f(fi[8][8])) ans++;

  cout << ans << endl;
}
