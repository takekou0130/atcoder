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

int n;
int a[202020];
ll use[202020];
ll mod =  1000000007;
ll tot = 1LL;

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, 202020) use[i] = 0;
  use[0] = 3;

  rep(i, n){
    if(use[a[i]] == 0) {
      cout << 0 << endl;
      return 0;
    }

    tot *= use[a[i]];
    tot %= mod;
    use[a[i]]--;
    use[a[i]+1]++;
  }

  cout << tot << endl;
}
