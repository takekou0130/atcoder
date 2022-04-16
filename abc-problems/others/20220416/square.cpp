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

int n, k;
ll arr[16];

int main(){
  cin >> n >> k;
  rep(i, n) cin >> arr[i];
  ll ans = 1e18;
  rep(i, pow(2, n)) {
    if (bit_count(i) != k) continue;
    int bit = i;
    ll max_h = 0;
    int idx = 0;
    ll sum = 0;
    while(bit > 0){
      if (bit & 1<<0){
        if (max_h >= arr[idx]){
          sum += max_h - arr[idx] + 1;
          max_h += 1;
        } else {
          chmax(max_h, arr[idx]);
        }
      } else {
        chmax(max_h, arr[idx]);
      }
      bit /= 2;
      idx++;
    }
    chmin(ans, sum);
  }
  cout << ans << endl;
}
