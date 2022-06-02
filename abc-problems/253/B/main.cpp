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

int h,w;
P koma1;
P koma2;

int main(){
  cin >> h >> w;
  bool used = false;
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w){
      if(s[j] == 'o'){
        if(!used){
          koma1 = {i, j};
          used = true;
        } else {
          koma2 = {i, j};
        }
      }
    }
  }
  cout << abs(koma1.first-koma2.first)+abs(koma1.second-koma2.second) << endl;
}
