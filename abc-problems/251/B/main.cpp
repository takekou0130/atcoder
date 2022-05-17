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

ll n, w;
ll arr[301];
set<ll> s;

int main(){
  cin >> n >> w;
  rep(i, n) cin >> arr[i];
  rep(i, n){
    if(arr[i] <= w) s.insert(arr[i]);
  }
  rep(i, n){
    rep(j, n){
      if(i == j) continue;
      ll ans = arr[i] + arr[j];
      if(ans <= w) s.insert(ans);
    }
  }

  rep(i, n){
    rep2(j,i+1, n){
      rep2(k,j+1, n){
        if(i == j || j == k || k == i) continue;
        ll ans = arr[i] + arr[j] + arr[k];
        if(ans <= w) s.insert(ans);
      }
    }
  }

  cout << s.size() << endl;
}
