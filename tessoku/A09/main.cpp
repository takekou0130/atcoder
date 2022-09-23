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
int a[101010],b[101010],c[101010],d[101010];
int fe[1515][1515];

int main(){
  cin >> h >> w >> n;
  rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
  rep(i, n) {a[i]--; b[i]--; c[i]--; d[i]--;}
  rep(i, 1515) rep(j, 1515) fe[i][j] = 0;

  rep(i, n) {
    fe[a[i]][b[i]]++;
    if(c[i] != h-1) fe[c[i]+1][b[i]]--;
    if(d[i] != w-1) fe[a[i]][d[i]+1]--;
    if(c[i] != h-1 && d[i] != w-1) fe[c[i]+1][d[i]+1]++;
  }

  rep(i, h) {
    rep(j, w) fe[i][j+1] += fe[i][j];
  }

  rep(j,w) {
    rep(i,h) fe[i+1][j] += fe[i][j];
  }

  rep(i,h) {
    rep(j, w) {
      cout << fe[i][j];
      if(j != w-1) cout << " ";
    }
    cout << endl;
  }


}
