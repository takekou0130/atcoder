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
int c[25];
int v[25];
int main(){
  cin >> n;
  rep(i, n) cin >> v[i];
  rep(i, n) cin >> c[i];
  int ans = -1e6;
  rep(i, pow(2, n)){
    int bit = i;
    int cnt = 0;
    int x = 0;
    int y = 0;
    while(bit != 0){
      if(bit & 1<<0){
        x += v[cnt];
        y += c[cnt];
      }
      cnt++;
      bit /= 2;
    }
    chmax(ans, x-y);
  }
  cout << ans << endl;
}
