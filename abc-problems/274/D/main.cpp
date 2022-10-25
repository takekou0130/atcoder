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

int n,x,y;
int a[1010];
// 偶数番目
vector<int> xa;
// -10000 した数
bool xdp[1010][20202];
// 奇数番目
vector<int> ya;
// -10000 した数
bool ydp[1010][20202];

int main(){
  cin >> n >> x >> y;
  rep(i, n) cin >> a[i];
  rep(i, 1010) rep(j, 20202) {
    xdp[i][j] = false;
    ydp[i][j] = false;
  }

  rep(i, n) {
    if(i%2 == 0) xa.push_back(a[i]);
    else ya.push_back(a[i]);
  }

  ydp[0][10000+ya[0]] = true;
  ydp[0][10000-ya[0]] = true;
  xdp[0][10000+xa[0]] = true;

  rep2(i, 1, xa.size()){
    rep(j, 20202){
      if(xdp[i-1][j]){
        if(j+xa[i] < 20202) xdp[i][j+xa[i]] = true;
        if(j-xa[i] >= 0) xdp[i][j-xa[i]] = true;
      }
    }
  }

  rep2(i,1, ya.size()){
    rep(j, 20202){
      if(ydp[i-1][j]){
        if(j+ya[i] < 20202) ydp[i][j+ya[i]] = true;
        if(j-ya[i] >= 0) ydp[i][j-ya[i]] = true;
      }
    }
  }

  if(xdp[xa.size()-1][10000+x] && ydp[ya.size()-1][10000+y]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
