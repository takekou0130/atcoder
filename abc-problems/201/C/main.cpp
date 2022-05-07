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
  int ans = 0;
  rep2(i, 0, 10000){
    int curr = i;
    int v[10] = {0};
    rep(j, 4){
      v[curr%10]++;
      curr /= 10;
    }
    bool flag = true;
    rep(i, 10){
      if(s[i] == 'o' && v[i] > 0){
        continue;
      }
      if(s[i] == 'x' && v[i] == 0){
        continue;
      }
      if(s[i] == '?'){
        continue;
      }
      flag = false;
    }
    if(flag) ans++;
  }
  cout << ans << endl;
}
