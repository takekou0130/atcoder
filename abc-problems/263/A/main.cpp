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

map<int, int> mp;

int main(){
  rep(i, 5){
    int in;
    cin >> in;
    mp[in]++;
  }

  if(mp.size() != 2) {
    cout << "No" << endl;
    return 0;
  }

  int f = 0;
  for(auto m: mp){
    if(f == 0) f = m.second;
    else if (f == 3 && m.second == 2) {
      cout << "Yes" << endl;
      return 0;
    }
    else if (f == 2 && m.second == 3) {
       cout << "Yes" << endl;
      return 0;
    }
    else {
      cout << "No" << endl;
      return 0;
    }
  }
}
