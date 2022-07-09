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

int h, w;
ll k,v;
ll a[126][126];
ll sum[128][128];
int main(){
  cin >> h >> w >> k >> v;
  rep(i, h) rep(j, w) {
    ll in;
    cin >> in;
    a[i][j] = in + k;
  }

  rep(i, 128) rep(j, 128) sum[i][j] = 0;

  rep(i, h) rep(j, w) {
    sum[i+1][j+1] = a[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
  }



  ll ans = 0;
  for(int len_h = 1; len_h <= h; len_h++){
    for(int len_w = 1; len_w <= w; len_w++){
      for(int i = 1; i+len_h-1 <= h; i++){
        for(int j = 1; j+len_w-1 <= w; j++){
          if(sum[i+len_h-1][j+len_w-1] - sum[i+len_h-1][j-1] - sum[i-1][j+len_w-1] + sum[i-1][j-1] <= v){
            chmax(ans, (ll)len_h * (ll)len_w);
          }
        }
      }
    }
  }

  cout << ans << endl;
}
