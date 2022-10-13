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
  int n;
  ll a[101010];
  cin >> n ;
  rep(i, n) cin >> a[i];
  int ki, ni, yon;
  ki = 0;
  ni = 0;
  yon = 0;
  rep(i, n) {
    if(a[i]%4 == 0) yon++;
    else if (a[i]%2 == 0) ni++;
    else ki++;
  }

  if((ki-yon) > 0 && ni > 0) cout << "No" << endl;
  else if ((ki - yon) > 1) cout << "No" << endl;
  else cout << "Yes" << endl;
}
