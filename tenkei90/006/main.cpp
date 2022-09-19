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

int n,k;
string s;
int mp[101010][26];
string orig = "abcdefghijklmnopqrstuvwxyz";

int main(){
  cin >> n >> k >> s;

  rep(i, 26){
    char targ = orig[i];
    int idx = -1;
    for(int j = s.size()-1; j >= 0; j--){
      if(s[j] == targ){
        idx = j;
      }
      mp[j][i] = idx;
    }
  }

  string ans = "";
  int idx = 0;
  rep(i, k){
    rep(j, 26){
      if(mp[idx][j] != -1 && s.size() - 1 - mp[idx][j] >= k - 1 - i){
        ans += orig[j];
        idx = mp[idx][j] + 1;
        break;
      }
    }
  }
  cout << ans << endl;
}
