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

int n, x, y, z;
int a[1010],b[1010], c[1010], seen[1010];
int main(){
  cin >> n >> x >> y >> z;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) c[i] = a[i]+b[i];
  rep(i, n) seen[i] = 0;
  set<int> gokaku;
  rep(j, x){
    ll ans = -1;
    ll idx = 0;
    rep(i, n){
      if(ans < a[i] && seen[i] == 0){
        ans = a[i];
        idx = i;
      }
      seen[idx] = 1;
      gokaku.insert(idx);
    }
  }

  rep(j, y){
    ll ans = -1;
    ll idx = 0;
    rep(i, n){
      if(ans < b[i] && seen[i] == 0){
        ans = b[i];
        idx = i;
      }
      seen[idx] = 1;
      gokaku.insert(idx);
    }
  }

  rep(j, z){
    ll ans = -1;
    ll idx = 0;
    rep(i, n){
      if(ans < c[i] && seen[i] == 0){
        ans = c[i];
        idx = i;
      }
    }
    seen[idx] = 1;
    gokaku.insert(idx);
  }

    auto itr = gokaku.begin();
  while(itr != gokaku.end()){
    int out = *itr;
    cout << out + 1 << endl;
    itr++;
  }

}
