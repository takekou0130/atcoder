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


int main(){
  double a,b,d;
  double pi = 3.141592653589793238;
  cin >> a >> b >> d;
  double dd = d / 180.0 * pi;
  cout << fixed << setprecision(10) << a * cos(dd) - b * sin(dd) << " ";
  cout << fixed << setprecision(10) << a * sin(dd) + b * cos(dd) << endl;
}
