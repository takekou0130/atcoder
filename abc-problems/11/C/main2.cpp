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
int dp[303];
int inf = 1e6;
vector<int> mov = {1,2,3};
int main(){
  cin >> n;
  rep(i, 303) dp[i] = inf;
  dp[n] = 0;
  rep(i, 3){
    int ng;
    cin >> ng;
    dp[ng] = -1;
  }
  for(int i = n; i > 0; i--){
    if(dp[i] == -1) continue;
    rep(j, 3){
      int next = i - mov[j];
      if(next < 0 || dp[next] == -1) continue;
      chmin(dp[next], dp[i]+1);
    }
  }
  if(dp[0] <= 100) cout << "YES" << endl;
  else cout << "NO" << endl;
}
