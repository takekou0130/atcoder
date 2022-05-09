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

ll n;

int main(){
  int inf = 1000000;
  vector<bool> isprime(inf+1, true);
  isprime[0] = isprime[1] = false;
  for(int p = 2; p <= inf; ++p){
    if(!isprime[p]) continue;
    for (int q = p * 2; q <= inf; q += p){
      isprime[q] = false;
    }
  }

  vector<ll> p;
  vector<ll> q3;
  for(ll i = 0; i <= inf; i++){
    if(isprime[i]){
      p.push_back(i);
      q3.push_back(i*i*i);
    }
  }

  cin >> n;

  ll ans = 0;
  for(int i = 1; i < q3.size(); i++){
    if(q3[i] > n) break;
    ll mp = n / q3[i];
    ll idx = upper_bound(p.begin(), p.end(), min(mp, p[i-1])) - p.begin();
    ans += idx;
  }
  cout << ans << endl;
}
