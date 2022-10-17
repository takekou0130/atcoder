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

ll t,a,s,a_i,s_i;

int main(){
  cin >> t;
  rep(i, t){
    cin >> a >> s;
    bool agari = false;
    bool ok = true;
    while(a > 0 || s > 0 || agari) {
      if(agari && a == 0 && s == 0){
        ok = false;
        break;
      }
      a_i = a%2;
      s_i = s%2;
      a /= 2;
      s /= 2;

      if(agari && a_i == 1){
        if(s_i == 0) {
          ok = false;
          break;
        }
        agari = true;
      }
      else if (agari && a_i == 0) {
        if(s_i == 0){
          agari = true;
        } else {
          agari = false;
        }
      }
      else if (!agari && a_i == 1) {
        if(s_i == 1) {
          ok = false;
          break;
        }
        agari = true;
      }
      else if (!agari && a_i == 0) {
        // any
      }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
