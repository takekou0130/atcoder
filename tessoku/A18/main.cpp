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

int n,s;
int a[65];
bool dp[65][10010];

int main(){
  cin >> n >> s;
  rep(i, n) cin >> a[i];

  rep(i, 65) rep(j, 10010) dp[i][j] = false;

  dp[0][a[0]] = true;
  dp[0][0] = true;

  rep(i, n-1){
    rep(j, s+1) {
      if(dp[i][j] && j + a[i+1] <= s) dp[i+1][j+a[i+1]] = true;
      if(dp[i][j]) dp[i+1][j] = true;
    }
  }

  if(!dp[n-1][s]) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> keiro;
  int sum = s;
  for(int i = n-1; i > 0; i--) {
    if(sum == 0) continue;
    if(dp[i-1][sum-a[i]]){
      sum -= a[i];
      keiro.push_back(i+1);
    }
  }
  if(sum != 0) keiro.push_back(1);

  reverse(keiro.begin(), keiro.end());

  cout << keiro.size() << endl;
  for(int i = 0; i < keiro.size(); i++) {
    cout << keiro[i];
    if(i != keiro.size()-1) cout << " ";
  }
  cout << endl;
}
