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

int main(){
  cin >> n;
  ll arr[5];
  rep(i, 5) arr[i] = (ll)0;
  rep(i, n){
    string c;
    cin >> c;
    if(c[0] == 'M') arr[0]++;
    if(c[0] == 'A') arr[1]++;
    if(c[0] == 'R') arr[2]++;
    if(c[0] == 'C') arr[3]++;
    if(c[0] == 'H') arr[4]++;
  }

  ll ans = 0;
  rep(i, 5){
    rep2(j, i+1, 5){
      rep2(k, j+1, 5){
        ans += arr[i] * arr[j] * arr[k];
      }
    }
  }
  cout << ans << endl;
}
