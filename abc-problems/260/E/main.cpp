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

int main(){
  map<int, int> mp;
  mp[2] = 20;
  mp[1] = 10;
  mp[3] = 30;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    auto val = *itr;
    cout << val.first << endl;
    cout << val.second << endl;
  }

  cout << "--------------" << endl;

  auto itr2 = mp.end();
  while(itr2 != mp.begin()){
    itr2--;
    auto val = *itr2;
    cout << val.first << endl;
    cout << val.second << endl;
  }
}
