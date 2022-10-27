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

ll mod = 1048576;
ll q;
ll a[1048576];
set<ll> st;

int main(){
  cin >> q;
  rep(i, mod) {
    a[i] = -1;
    st.insert(i);
  }

  rep(qi, q){
    int t;
    ll x;
    cin >> t >> x;
    if(t == 1) {
      ll x_mod = x % mod;
      auto itr = st.lower_bound(x_mod);
      if(itr != st.end()){
        a[*itr] = x;
        st.erase(*itr);
      } else {
        auto itr2 = st.lower_bound(0);
        a[*itr2] = x;
        st.erase(*itr2);
      }
    }
    if(t == 2){
      cout << a[x%mod] << endl;
    }
  }
}
