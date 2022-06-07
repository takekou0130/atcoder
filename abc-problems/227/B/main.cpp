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

int f(int a, int b){
  return 4*a*b + 3*a + 3*b;
}

int main(){
  set<int> st;
  rep2(a,1,1000){
    rep2(b,1,1000){
      st.insert(f(a,b));
    }
  }

  int n;
  cin >> n;
  int ans = 0;
  rep(i, n){
    int s;
    cin >> s;
    if(st.count(s) == 0) ans++;
  }

  cout << ans << endl;
}
