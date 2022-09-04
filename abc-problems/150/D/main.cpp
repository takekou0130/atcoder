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

ll n,m;
vector<ll> a;
vector<ll> han;

int test(){
  ll ans = 0;
  rep(i, m){
    bool flag = true;
    rep(j, n){
      bool flag2 = false;
      rep(k, m){
        if(i == a[j]*(k+0.5)) flag2 = true;
      }
      if(!flag2){
        flag = false;
        break;
      }
    }
    if(flag) ans++;
  }
  cout << ans << endl;
  return 0;
}

int act(){
  rep(i,n) han.push_back(a[i]/2);
  ll lcmnum = han[0];
  rep(i, n) lcmnum = lcm(lcmnum, han[i]);
  rep(i, n) {
    if((lcmnum/han[i])%2 == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  if (lcmnum > m){
    cout << 0 << endl;
    return 0;
  }
  cout << (m/lcmnum-1LL)/2LL+1LL << endl;
  return 0;
}

int main(){
  cin >> n >> m;
  rep(i, n) {
    ll an; cin >> an; a.push_back(an);
  }

  act();
}
