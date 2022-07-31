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

int n,k;
string s;
vector<ll> v;

int main(){
  cin >> n >> k >> s;
  char past = s[0];
  ll now = 0;
  rep(i, n){
    if(past == s[i]) now++;
    else {
      v.push_back(now);
      now = 1;
      past = s[i];
    }
    if(i == n-1) v.push_back(now);
  }

  vector<ll> sum(v.size()+1, 0);
  rep(i, v.size()){
    sum[i+1] = sum[i] + v[i];
  }

  // 1始まり
  if(s[0] == '1'){
    ll ans = 0;
    rep(i, sum.size()){
      if(i%2 == 1){
        int idx = i+k*2;
        if (idx >= sum.size()) idx = sum.size() -1;
        chmax(ans,sum[idx] - sum[i-1]);
      }
    }
    cout << ans << endl;
  // 0始まり
  } else {
    ll ans = 0;
    rep(i, sum.size()){
      if(i%2 == 0){
        int idx = i+k*2;
        if (idx >= sum.size()) idx = sum.size() -1;
        chmax(ans,sum[idx] - max(sum[i-1],0LL));
      }
    }
    cout << ans << endl;
  }
}
