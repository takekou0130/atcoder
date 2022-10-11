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
set<int> st;

int main(){
  cin >> n >> k;
  rep(i, k) {
    int d;
    cin >> d;
    st.insert(d);
  }

  while(true) {
    int now = n;
    bool flg = true;
    while(now > 0) {
      if(st.count(now%10)) {
        flg = false;
        break;
      }
      now /= 10;
    }
    if(flg) {
      cout << n << endl;
      return 0;
    }
    n++;
  }
}
