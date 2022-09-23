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
ll a[101010],b[101010];
ll dp[101020];
ll inf = 10000000;

int main(){
  cin >> n;
  a[0] = inf;
  b[0] = inf;
  b[1] = inf;
  rep(i, n-1) cin >> a[i+1];
  rep(i, n-2) cin >> b[i+2];

  dp[0] = 0;
  dp[1] = a[1];
  rep2(i, 2, n) {
    dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i]);
  }

  vector<int> keiro;
  int idx = n-1;
  keiro.push_back(idx+1);
  while(idx > 1) {
    if(dp[idx]-dp[idx-2] == b[idx]) {
      idx -= 2;
      keiro.push_back(idx+1);
      if(idx == 1) keiro.push_back(1);
    }
    else {
      idx -= 1;
      keiro.push_back(idx+1);
      if(idx == 1) keiro.push_back(1);
    }
  }

  reverse(keiro.begin(), keiro.end());

  cout << keiro.size() << endl;
  for(int i = 0; i < keiro.size(); i++) {
    cout << keiro[i];
    if(i != keiro.size()-1) cout << " ";
  }
  cout << endl;
}
