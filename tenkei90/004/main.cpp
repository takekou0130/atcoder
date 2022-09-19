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
int v[2020][2020];
int h_v[2020];
int w_v[2020];

int main(){
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> v[i][j];

  rep(i, h) {
    int sum = 0;
    rep(j, w) sum += v[i][j];
    h_v[i] = sum;
  }

  rep(j, w) {
    int sum = 0;
    rep(i, h) sum += v[i][j];
    w_v[j] = sum;
  }

  rep(i, h) {
    rep(j, w){
      cout << w_v[j]+h_v[i]-v[i][j];
      if(j != w-1) cout << " ";
    }
    cout << endl;
  }
}
