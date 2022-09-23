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
ll k;
vector<ll> ze;
vector<ll> ko;
set<ll> zen;
set<ll> kou;

int main(){
  cin >> n >> k;
  rep(i, n){
    ll in; cin >> in;
    if(i <= 15) ze.push_back(in);
    else ko.push_back(in);
  }

  rep(i, pow(2, ze.size())){
    int bit = i;
    int cnt = 0;
    ll tot = 0;
    while(bit > 0){
      if(bit & 1) tot += ze[cnt];
      cnt++;
      bit /= 2;
    }
    zen.insert(tot);
  }

  rep(i, pow(2, ko.size())){
    int bit = i;
    int cnt = 0;
    ll tot = 0;
    while(bit > 0){
      if(bit & 1) tot += ko[cnt];
      cnt++;
      bit /= 2;
    }
    kou.insert(tot);
  }

  for(auto z: zen) {
    if(kou.count(k-z)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}
