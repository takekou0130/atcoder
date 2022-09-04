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

ll a,b,k;

int main(){
  cin >> a >> b >> k;
  if(k <= a) {
    cout << a - k << " " << b << endl;
    return 0;
  }

  if(k <= a+b) {
    cout << 0 << " " << b - (k - a) << endl;
    return 0;
  }

  cout << 0 << " " << 0 << endl;
}
