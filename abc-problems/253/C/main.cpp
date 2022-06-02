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

map<ll, ll> mp;
set<ll> st;
ll q;

int main(){
  cin >> q;
  rep(i, q){
    int j;
    cin >> j;
    if(j == 1){
      ll x;
      cin >> x;
      mp[x]++;
      st.insert(x);
    }
    if(j == 2){
      ll x, c;
      cin >> x >> c;
      if(mp[x] > c){
        mp[x] -= c;
      } else {
        mp[x] = 0;
        st.erase(x);
      }
    }
    if(j == 3){
      auto en = st.end();
      en--;
      cout << *en - *st.begin() << endl;
    }
  }
}
