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

set<ll> st;
map<ll, ll> mp;

int main(){
  int q;
  cin >> q;
  rep(iq, q){
    int c;
    cin >> c;
    if(c == 1) {
      ll x;
      cin >> x;
      st.insert(x);
      mp[x]++;
    }
    if(c == 2) {
      ll x,k;
      cin >> x >> k;
      auto itr = st.upper_bound(x);
      ll ans;
      while(k > 0){
        if(itr == st.begin()) {
          ans = -1;
          break;
        }

        itr--;
        if(mp[*itr] >= k) {
          ans = *itr;
          break;
        } else {
          k -= mp[*itr];
        }
      }
      cout << ans << endl;
    }
    if(c == 3) {
      ll x,k;
      cin >> x >> k;
      auto itr = st.lower_bound(x);
      ll ans;
      while(k > 0){
        if(itr == st.end()) {
          ans = -1;
          break;
        }

        if(mp[*itr] >= k) {
          ans = *itr;
          break;
        } else {
          k -= mp[*itr];
          itr++;
        }
      }
      cout << ans << endl;
    }
  }
}
