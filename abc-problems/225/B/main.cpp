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
int a[101010],b[101010];
bool use[101010];

int main(){
  cin >> n;
  rep(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    use[i] = false;
  }

  use[a[0]] = true;
  use[b[0]] = true;
  int tar = a[0];
  rep2(i, 1, n-1) {
    if(a[i] == tar) use[b[i]] = true;
    if(b[i] == tar) use[a[i]] = true;
  }
  bool flg = true;
  rep(i, n) {
    if(!use[i]){
      flg = false;
      break;
    }
  }
  if(flg) {
    cout << "Yes" << endl;
    return 0;
  }

  rep(i, n) use[i] = false;
  use[a[0]] = true;
  use[b[0]] = true;
  tar = b[0];
  rep2(i, 1, n-1) {
    if(a[i] == tar) use[b[i]] = true;
    if(b[i] == tar) use[a[i]] = true;
  }
  flg = true;
  rep(i, n) {
    if(!use[i]){
      flg = false;
      break;
    }
  }
  if(flg) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
}
