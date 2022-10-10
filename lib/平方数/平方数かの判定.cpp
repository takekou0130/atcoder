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

// 1e7まではとりあえずOK
// O(1)
bool is_squere(ll N) {
    ll r = (ll)floor(sqrt((ld)N));  // 切り捨てした平方根
    return (r * r) == N;
}

// O(sqrt(N))
bool is_squere_route(ll N) {
  for(ll i = 1; i * i <= N; i++) {
    if(i * i == N) return true;
  }
  return false;
}

int main(){
  rep(i, 1e8) {
    if(is_squere(i)) cout << i << endl;
  }
}
