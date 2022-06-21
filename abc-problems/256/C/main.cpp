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

ll h_1,h_2,h_3,w_1,w_2,w_3;

// i    j  c_1
// k    l  c_2
// c_3 c_4 c_5
ll ans = 0;
int main(){
  cin >>  h_1 >> h_2 >> h_3 >> w_1 >> w_2 >> w_3;
  rep2(i, 1, 29){
    rep2(j, 1, 29){
      rep2(k, 1, 29){
        rep2(l, 1, 29){
          if(i+j > 30 || k+l > 30 || i+k > 30 || j+l > 30) continue;
          int c_1 = h_1 - i - j;
          int c_2 = h_2 - k - l;
          int c_3 = w_1 - i - k;
          int c_4 = w_2 - j - l;
          int c_5 = w_3 - c_1 - c_2;
          if(c_1 <= 0 || c_2 <= 0 || c_3 <= 0 || c_4 <= 0 || c_5 <= 0) continue;
          if(c_3+c_4+c_5 == h_3) ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
