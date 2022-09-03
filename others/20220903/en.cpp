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

int n,m;
ld x[101], y[101], r[101];
ld x_m[101], y_m[101];

bool sep(ld x_1, ld y_1, ld r_1, ld x_2, ld y_2, ld r_2){
  ld dis = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
  return dis > r_1 + r_2;
}

bool check(ld r_t){
  rep(i, m) {
    rep(j, n){
      if(!sep(x[j], y[j], r[j], x_m[i], y_m[i], r_t)) return false;
    }
  }
  rep(i, m){
    rep(j, m){
      if(j == i) continue;
      if(!sep(x_m[j], y_m[j], r_t, x_m[i], y_m[i], r_t)) return false;
    }
  }
  return true;
}

int main(){
  cin >> n >> m;
  rep(i, n) cin >> x[i] >> y[i] >> r[i];
  rep(i, m) cin >> x_m[i] >> y_m[i];

  // rを求める
  ld ok = 0.1;
  ld ng = 10000;
  while(ng - ok > 0.000000001){
    ld mid = ok + (ng-ok) / (ld)2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  ld ans = ok;
  rep(i, n) chmin(ok, r[i]);
  cout <<fixed << setprecision(7)<< ok << endl;
}
