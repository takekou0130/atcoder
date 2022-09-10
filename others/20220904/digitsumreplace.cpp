#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld ;
// ここintにしたら通ったw
typedef pair<int,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define endl "\n"
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b

ll m;
ll ans = 0;
// digit, 数
vector<P> dp;
// 足した結果, 必要な回数
P calc[10] = {{0,1},{2,1},{4,1},{6,1},{8,1},{1,2},{3,2},{5,2},{7,2},{9,2}};

int main(){
  cin >> m;
  rep(i, m){
    int d;
    ll c;
    cin >> d >> c;
    dp.push_back({d,c});
  }

  while(true) {
    bool end = true;
    vector<P> newDp;
    for(auto p: dp){
      if(p.second == 1){
        newDp.push_back(p);
        continue;
      }
      if(p.second % 2 == 0){
        ans += calc[p.first].second * (p.second / 2);
        newDp.push_back({calc[p.first].first, p.second / 2});
      } else {
        ans += calc[p.first].second * (p.second / 2);
        newDp.push_back({calc[p.first].first, p.second / 2});
        newDp.push_back({p.first, 1});
      }
      end = false;
    }

    dp = newDp;
    if(end) break;
  }

  while(dp.size() > 1){
    vector<P> newDp;

    for(int i = 0; i < dp.size()-1; i += 2){
      int sum = dp[i].first + dp[i+1].first;
      ans += 1LL;
      if(sum >= 10){
        sum = (sum%10) + (sum/10);
        ans += 1LL;
      }

      newDp.push_back({sum, 1});
    }

    if(dp.size()%2 == 1) newDp.push_back(dp[dp.size()-1]);

    dp = newDp;
  }

  cout << ans << endl;
}
