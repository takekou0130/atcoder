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

ld n;

ld calc(ld v) {
  return v * v * v + v;
}

bool check(ld v) {
  return calc(v) - n >= 0;
}

int main(){
  cin >> n;

  ld ok = 100;
  ld ng = 0;
  while(abs(calc(ok) - n) > 0.00001) {
    ld mid = ng + (ok - ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }

  cout << fixed << setprecision(10) << ok << endl;
}
