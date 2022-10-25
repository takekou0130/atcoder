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
  int h,w;
  cin >> h >> w;
  char c[1010][1010];
  vector<char> ans;
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w){
      c[i][j] = s[j];
    }
  }

  rep(j, w){
    int tot = 0;
    rep(i, h){
      if(c[i][j] == '#') tot++;
    }
    ans.push_back(tot);
  }

  rep(j, w){
    cout << ans[j] << endl;
  }
}
