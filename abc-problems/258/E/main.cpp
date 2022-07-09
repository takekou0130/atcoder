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

vector<ll> v;
ll n,q,x;
ll w[202020];
ll sum[202021];
int main(){
  cin >> n >> q >> x;
  rep(i, n) cin >> w[i];
  sum[0] = 0;
  rep(i, n){
    sum[i+1] = sum[i] + w[i];
  }


}
