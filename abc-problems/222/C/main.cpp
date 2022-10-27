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

int n,m;
char te[202][101];

bool sakigachi(char saki, char ato) {
  if(saki == 'G' && ato == 'C') return true;
  if(saki == 'P' && ato == 'G') return true;
  if(saki == 'C' && ato == 'P') return true;

  return false;
}

int main(){
  cin >> n >> m;
  rep(i, 2*n){
    string s;
    cin >> s;
    rep(j, m) te[i][j] = s[j];
  }

  // -score, num
  vector<P> ran;
  rep(i, 2 * n) {
    ran.push_back({0, i});
  }

  rep(i, m){
    vector<P> nran;
    for(int j = 0; j < 2*n; j += 2) {
      char saki = te[ran[j].second][i];
      char ato = te[ran[j+1].second][i];
      if(saki == ato){
        nran.push_back({ran[j]});
        nran.push_back({ran[j+1]});
        continue;
      }

      if(sakigachi(saki, ato)){
        nran.push_back({ran[j].first - 1, ran[j].second});
        nran.push_back({ran[j+1]});
      } else {
        nran.push_back({ran[j]});
        nran.push_back({ran[j+1].first - 1, ran[j+1].second});
      }
    }

    sort(nran.begin(), nran.end());
    ran = nran;
  }

  for(auto [r,l]: ran){
    cout << l+1 << endl;
  }
}
