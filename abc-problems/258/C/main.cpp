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

ll n,q;
string s;
int main(){
  cin >> n >> q >> s;
  ll now_zero = 0;
  rep(i, q){
    ll t, x;
    cin >> t  >> x;
    if(t == 1){
      now_zero = (now_zero - x + n) % n;
    }
    if(t == 2){
      cout << s[(now_zero+x-1)%n] << endl;
    }
  }
}
