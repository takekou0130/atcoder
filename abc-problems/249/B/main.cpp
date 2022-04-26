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

string s;

int main(){
  cin >> s;
  map<char, int> oo;
  vector<char> ool;
  map<char, int> ko;
  vector<char> kol;
  rep(i, s.size()){
    char now = s[i];
    if(islower(now)){
      kol.push_back(now);
      ko[now]++;
    } else {
      ool.push_back(now);
      oo[now]++;
    }
  }
  bool flag = true;
  for(auto moji: ool){
    if (oo[moji] > 1) flag = false;
  }
  for(auto moji: kol){
    if (ko[moji] > 1) flag = false;
  }

  if(ool.size() != 0 && kol.size() != 0 && flag){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
