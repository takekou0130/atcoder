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


ll x[4], y[4];
int main(){
  rep(i, 4) cin >> x[i] >> y[i];
  rep(i, 4){
    P a = {x[i] - x[(i+1)%4], y[i] - y[(i+1)%4]};
    P b = {x[(i+2)%4] - x[(i+1)%4], y[(i+2)%4] - y[(i+1)%4]};
    if(a.first*b.second-a.second*b.first > 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
