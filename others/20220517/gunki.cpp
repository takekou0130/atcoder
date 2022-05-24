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
char arr[5][1010];
// RBW
int cost[3][1010];
ll dp[3][1010];
string rbw = "RBW";
ll inf = 1e18;
int main(){
  cin >> n;
  rep(i, 5){
    string s;
    cin >> s;
    rep(j, n) arr[i][j] = s[j];
  }

  rep(j, n){
    rep(i, 3){
      int cos = 0;
      rep(k, 5){
        if(arr[k][j] == rbw[i]) continue;
        cos++;
      }
      cost[i][j] = cos;
    }
  }

  rep(j, n){
    rep(i, 3){
      dp[i][j] = inf;
    }
  }

  rep(i, 3) dp[i][0] = cost[i][0];

  rep(j, n){
    rep(i, 3){
      rep(k, 3){
        if(i == k) continue;
        chmin(dp[k][j+1], dp[i][j]+cost[k][j+1]);
      }
    }
  }

  cout << min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1])) << endl;
}
