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

int conv(string s) {
  int h = stoi(s.substr(0,2));
  int m = stoi(s.substr(3,2));
  int se = stoi(s.substr(6,2));
  cout << h << " " << m << " " << se;
  return h*60*60 + m*60 + se;
}

int main(){
  while(true){
    int n;
    cin >> n;
    if(n == 0) break;
    map<int, int> mp;
    rep(i, n){
      string st,go;
      cin >> st >> go;
      int ss = conv(st);
      int gg = conv(go);
      mp[ss]++;
      mp[gg]--;
    }

    int ans = 0;
    int now = 0;
    for(auto m: mp){
      now += m.second;
      chmax(ans, now);
    }

    cout << ans << endl;
  }
}
