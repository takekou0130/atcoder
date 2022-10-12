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
int p[100];
int over = 0;

int main(){
  cin >> n;
  rep(i, 100) p[i] = 0;
  rep(i, n) {
    int a;
    cin >> a;
    if(a >= 3200) over++;
    else p[a/400]++;
  }
  ll mx = 0;
  ll mn = 0;
  rep(i, 8) {
    if(p[i] > 0) {
      mx++;
      mn++;
    }
  }

  if(mn == 0) cout << 1;
  else cout << mn;
  cout << " ";
  cout << mx + over << endl;
}
