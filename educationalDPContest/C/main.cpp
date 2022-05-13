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
int k[101010][3];
ll dp[101010][3] = {0};

int main(){
  cin >> n;
  rep(i, n) {
    cin >> k[i][0] >> k[i][1] >> k[i][2];
  }
  rep(j, 3){
    dp[0][j] = k[0][j];
  }

  rep(i, n){
    rep(j, 3){
      if(j != 0){
        chmax(dp[i+1][0], dp[i][j]+k[i+1][0]);
      }
      if(j != 1){
        chmax(dp[i+1][1], dp[i][j]+k[i+1][1]);
      }
      if(j != 2){
        chmax(dp[i+1][2], dp[i][j]+k[i+1][2]);
      }
    }
  }

  cout << max(max(dp[n-1][0], dp[n-1][1]),dp[n-1][2]) << endl;
}
