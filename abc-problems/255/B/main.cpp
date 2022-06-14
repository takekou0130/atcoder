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

int n,k;
vector<int> a;
ld hito[1010][2];

int main(){
  cin >> n >> k;
  rep(i, k){
    int ain;
    cin >> ain;
    ain--;
    a.push_back(ain);
  }

  rep(i, n){
    ld x,y;
    cin >> x >> y;
    hito[i][0] = x;
    hito[i][1] = y;
  }

  ld ans = 0;
  rep(i, n){
    ld res = 1e18;
    rep(j, k){
      chmin(res, abs(hito[i][0]-hito[a[j]][0]) * abs(hito[i][0]-hito[a[j]][0]) + abs(hito[i][1]-hito[a[j]][1]) * abs(hito[i][1]-hito[a[j]][1]));
    }
    chmax(ans, res);
  }
  cout << fixed << setprecision(10) << sqrtl(ans) << endl;
}
