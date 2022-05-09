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

  vector<ll> pnum;
  vector<ll> pnum3;
  rep(i, inf+1){
    if(isprime[i]){
      ll l = (ll)i;
      pnum.push_back(l);
      pnum3.push_back(l*l*l);
    }
  }

  cin >> n;

  ll ans = 0;
  for(int i = 0; i < pnum.size(); i++){
    if(pnum3[i] > n) break;
    for(int j = 0; j < i; j++){
      if(i == j) continue;
      if(pnum3[i] * pnum[j] > n) break;
      ans++;
    }
  }
  cout << ans << endl;
}
