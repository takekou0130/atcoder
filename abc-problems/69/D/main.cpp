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

int h,w,n;
int a[10101];
int fed[101][101];

int main(){
  cin >> h >> w >> n;
  rep(i, n) cin >> a[i];
  int c_h = 0;
  int c_w = 0;
  rep(i, n) {
    int cnt = a[i];
    rep(j, cnt) {
      fed[c_h][c_w] = i+1;
      if(c_w == w-1){
        c_w = 0;
        c_h++;
      } else {
        c_w++;
      }
    }
  }
  rep(i, h) {
    if(i%2 == 0) {
      rep(j, w) {
        cout << fed[i][j];
        if(j != w-1) cout << " ";
      }
      cout << endl;
    } else {
      for(int j = w-1; j >= 0; j--){
        cout << fed[i][j];
        if(j != 0) cout << " ";
      }
      cout << endl;
    }
  }
}
