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
ll a[101010];
ll L[101010];
ll INF = 1e9;

int main(){
  cin >> n ;
  rep(i, n) cin >> a[i];
  rep(i, 101010) L[i] = INF;

  L[0] = 0;
  L[1] = a[0];
  rep2(i, 1, n) {
    int idx = upper_bound(L, L+n, a[i]) - L;
    if(L[idx-1] < a[i]) L[idx] = a[i];
  }

  rep(i, n+2) {
    if(L[i] == INF) {
      cout << i-1 << endl;
      return 0;
    }
  }
}
