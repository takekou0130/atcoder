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

ll n,x;
string s;

int main(){
  cin >> n >> x >> s;
  ll ans = x;
  ll stock = 0;
  rep(i, n){
    if(stock > 0 || ( (s[i] == 'R' || s[i] == 'L') && ans*2LL > 1e18)){
      if(s[i] == 'R' || s[i] == 'L') stock++;
      else stock--;
      continue;
    }
    if(s[i] == 'U') ans /= 2LL;
    if(s[i] == 'R') ans = ans * 2LL + 1LL;
    if(s[i] == 'L') ans = ans * 2LL;
  }

  cout << ans << endl;
}
