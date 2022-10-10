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

string s;
set<char> st;
int main(){
  cin >> s;
  rep(i, 3) st.insert(s[i]);

  if(st.size() == 1) {
    cout << 1 << endl;
  } else if (st.size() == 2) {
    cout << 3 << endl;
  } else {
    cout << 6 << endl;
  }
}
