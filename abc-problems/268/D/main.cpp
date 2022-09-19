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
int m;
vector<int> per;
string s[9];
set<string> t;

string trim(string orig) {
  while(true){
    if(orig[orig.size()-1] == '_') orig.pop_back();
    else {
      break;
    }
  }
  while(true){
    if(orig[0] == '_') orig.erase(0,1);
    else {
      return orig;
    }
  }
}

int main(){
  cin >> n >> m;
  rep(i, n){
    string st;
    cin >> st;
    st += '_';
    per.push_back(i);
    s[i] = st;
  }
  rep(i, m){
    string st;
    cin >> st;
    t.insert(st);
  }

  int tot = 0;
  rep(i, n) {
    tot += s[i].size() - 1;
  }

  if(n == 1 && (tot == 1 || tot == 2)) {
    cout << -1 << endl;
    return 0;
  }

  int yobun = 16 - tot - n + 1 ;
  s[8] = "_";
  rep(i, yobun) per.push_back(8);

  do {
    string res = "";
    for(auto st: per) res += s[st];

    string ans = trim(res);
    if (!t.count(ans)){
      cout << ans << endl;
      return 0;
    }

  } while (next_permutation(per.begin(), per.end()));

  cout << -1 << endl;
  return 0;

}
