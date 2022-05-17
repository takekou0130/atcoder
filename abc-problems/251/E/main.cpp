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

ll w;
// つくれるか
bool ok[10101010];
vector<ll> db;
vector<ll> v;

int main(){
  cin >> w;
  rep(i, w) ok[i] = false;
  rep2(i, 1, w+1){
    if(ok[i]) continue;
    v.push_back(i);
    ok[i] = true;
    rep(j, db.size()){
      ok[i+db[j]] = true;
    }
    rep(j, v.size()-1){
      ok[i+v[j]] = true;
      db.push_back(i+v[j]);
    }
  }

  cout << v.size() << endl;
  rep(i, v.size()){
    cout << v[i] << " ";
  }
  cout << endl;
}
