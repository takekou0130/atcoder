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
  int zero_s = 0;
  rep(i, s.size()){
    if(i%2 == 0){
      if(s[i] != '0') zero_s++;
    } else {
      if(s[i] != '1') zero_s++;
    }
  }
  int ichi_s = 0;
  rep(i, s.size()){
    if(i%2 == 1){
      if(s[i] != '0') ichi_s++;
    } else {
      if(s[i] != '1') ichi_s++;
    }
  }
  cout << min(zero_s, ichi_s) << endl;
}
