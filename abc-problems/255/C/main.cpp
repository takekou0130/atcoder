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

ll x, a, d, n;

int main(){
  cin >> x >> a >> d >> n;
  if(d == 0){
    cout << abs(x-a) << endl;
    return 0;
  } else if (d > 0){
    if(a > x){
      cout << abs(x-a) << endl;
      return 0;
    } else if(x > a+d*(n-1)) {
      cout << abs(x-(a+d*(n-1))) << endl;
      return 0;
    } else {
      ll po = ((x - a) / d ) + 1;
      cout << min(abs(a+d*(po-1) - x), abs(a+d*po - x)) << endl;
      return 0;
    }
  } else if (d < 0){
    if(a < x){
      cout << abs(x-a) << endl;
      return 0;
    } else if(x < a+d*(n-1)){
      cout << abs(x-(a+d*(n-1))) << endl;
    } else {
       ll po = ((x - a) / d ) + 1;
      cout << min(abs(a+d*(po-1) - x), abs(a+d*po - x)) << endl;
      return 0;
    }
  }
}
