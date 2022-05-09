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

int n, w;
ll dp[10101][101];
int arr[101][2];

int main(){
  cin >> n >> w;
  rep(i,n){
    cin >> arr[i][0] >> arr[i][1];
  }

  rep(i, w+1){
    if(arr[0][1] <= i) dp[i][0] = arr[0][0];
    else dp[i][0] = 0;
  }

  rep(i, w+1){
    rep2(j, 1, n){
      if(i-arr[j][1] < 0) dp[i][j] = dp[i][j-1];
      else dp[i][j] = max(dp[i][j-1], arr[j][0]+dp[i-arr[j][1]][j-1]);
    }
  }


  cout << dp[w][n-1] << endl;
}
