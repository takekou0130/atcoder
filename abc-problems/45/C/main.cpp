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

ll cnt[11][11];

int main(){
  string s;
  cin >> s;
  int n = s.size();

  ll tot = 0;
  for(ll i = 0; i < n; i++) {
    ll base = s[i] - '0';
    ll dec = pow(10, n-i-1);
    ll cnt = pow(2, i);
    tot += base * dec * cnt;
    while(dec > 1) {
      dec /= 10;
      tot += base * dec * cnt;
      cnt *= 2;
    }
  }

  cout << tot << endl;
}
