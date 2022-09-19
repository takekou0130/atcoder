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

int n,q;
vector<ll> a;

int main(){
  cin >> n;
  rep(i, n) {
    ll in; cin >> in; a.push_back(in);
  }

  sort(a.begin(), a.end());
  cin >> q;
  rep(i, q){
    ll b; cin >> b;
    if(a[0] >= b) {
      cout << a[0] - b << endl;
      continue;
    }

    if(a[n-1] <= b) {
      cout << b - a[n-1] << endl;
      continue;
    }

    int low_itr = lower_bound(a.begin(), a.end(), b) - a.begin();
    if(low_itr == 0){
      cout << abs(a[0]-b) << endl;
      continue;
    }
    cout << min(abs(b-a[low_itr]), abs(b-a[low_itr-1])) << endl;
  }
}
