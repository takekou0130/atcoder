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
ll a[202020];
vector<ll> kisu;
vector<ll> gusu;

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) {
    if(a[i] % 2 == 0){
      gusu.push_back(a[i]);
    } else {
      kisu.push_back(a[i]);
    }
  }

  if(gusu.size() < 2 && kisu.size() < 2) {
    cout << -1 << endl;
    return 0;
  }

  sort(gusu.begin(), gusu.end());
  sort(kisu.begin(), kisu.end());

  if(gusu.size() < 2) {
    cout << kisu[kisu.size()-1] + kisu[kisu.size()-2] << endl;
    return 0;
  }

  if(kisu.size() < 2) {
    cout << gusu[gusu.size()-1] + gusu[gusu.size() - 2] << endl;
    return 0;
  }

  cout << max(kisu[kisu.size()-1] + kisu[kisu.size()-2], gusu[gusu.size()-1] + gusu[gusu.size() - 2]) << endl;
}
