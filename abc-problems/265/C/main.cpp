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

int h,w;
char fi[505][505];
bool seen[505][505];

// udlr
int h_mv[4] = {-1, 1, 0, 0};
int w_mv[4] = {0, 0, -1, 1};

bool check_move(int h_next, int w_next){
  if (h_next < 0 || h_next >= h) return false;
  if (w_next < 0 || w_next >= w) return false;
  return true;
}

int main(){
  cin >> h >> w;
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) fi[i][j] = s[j];
  }

  rep(i, 505) rep(j, 505) seen[i][j] = false;

  int h_n = 0;
  int w_n = 0;
  seen[0][0] = true;
  while(true){
    if(fi[h_n][w_n] == 'U') {
      int h_ne = h_n+h_mv[0];
      int w_ne = w_n+w_mv[0];
      if(seen[h_ne][w_ne]){
        cout << -1 << endl;
        return 0;
      } else if (!check_move(h_ne, w_ne)) {
        break;
      } else {
        h_n = h_ne;
        w_n = w_ne;
        seen[h_ne][w_ne] = true;
      }
    }

    if(fi[h_n][w_n] == 'D') {
      int h_ne = h_n+h_mv[1];
      int w_ne = w_n+w_mv[1];
      if(seen[h_ne][w_ne]){
        cout << -1 << endl;
        return 0;
      } else if (!check_move(h_ne, w_ne)) {
        break;
      } else {
        h_n = h_ne;
        w_n = w_ne;
        seen[h_ne][w_ne] = true;
      }
    }

    if(fi[h_n][w_n] == 'L') {
      int h_ne = h_n+h_mv[2];
      int w_ne = w_n+w_mv[2];
      if(seen[h_ne][w_ne]){
        cout << -1 << endl;
        return 0;
      } else if (!check_move(h_ne, w_ne)) {
        break;
      } else {
        h_n = h_ne;
        w_n = w_ne;
        seen[h_ne][w_ne] = true;
      }
    }

    if(fi[h_n][w_n] == 'R') {
      int h_ne = h_n+h_mv[3];
      int w_ne = w_n+w_mv[3];
      if(seen[h_ne][w_ne]){
        cout << -1 << endl;
        return 0;
      } else if (!check_move(h_ne, w_ne)) {
        break;
      } else {
        h_n = h_ne;
        w_n = w_ne;
        seen[h_ne][w_ne] = true;
      }
    }
  }

  cout << h_n + 1 << " " << w_n + 1 << endl;
}
