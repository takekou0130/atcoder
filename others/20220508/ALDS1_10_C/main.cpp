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

int q;

int main(){
  cin >> q;
  rep(que, q){
    string x, y;
    cin >> x >> y;
    int dp[1010][1010] = {0};
    rep(i, x.size()+1){
      rep(j, y.size()+1){
        if(x[i] == y[j]) dp[i+1][j+1] = max(dp[i+1][j], max(dp[i][j+1], dp[i][j]+1));
        else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }

    cout << dp[x.size()][y.size()] << endl;
  }
}
