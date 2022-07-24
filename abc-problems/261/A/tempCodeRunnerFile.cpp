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

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int v[110];
  rep(i, 110) v[i] = 0;
  for(int i = a; i <= b; i++){
    v[i]++;
  }
  for(int i = c; i <= d; i++){
    v[i]++;
  }

  int ans = -1;
  rep(i, 110) {
    if(v[i] == 2) ans++;
  }
  cout << ans << endl;
}
