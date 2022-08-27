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
  int x, y ,n;
  cin >> x >> y >> n;
  if (x <= (y/3)) {
    cout << x * n << endl;
  } else {
    int sum = 0;
    while(n > 0){
      if(n >= 3){
        sum += y;
        n -= 3;
      } else {
        sum += x;
        n -= 1;
      }
    }
    cout << sum << endl;
  }
}
