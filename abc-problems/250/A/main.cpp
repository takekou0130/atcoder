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

int h, w, r, c;

int main(){
  cin >> h >> w >> r >> c;
  if(h == 1 && w == 1){
    cout << 0 << endl;
    return 0;
  }
  if(h != 1 && w != 1){
    if(r == 1 && c == 1){
      cout << 2 << endl;
      return 0;
    }
    if(r == 1 && c == w){
      cout << 2 << endl;
      return 0;
    }
    if(r == h && c == w){
      cout << 2 << endl;
      return 0;
    }
    if(r == h && c == 1){
      cout << 2 << endl;
      return 0;
    }
    if(r == 1 || r == h || c == 1 || c == w){
      cout << 3 << endl;
      return 0;
    }
    cout << 4 << endl;
    return 0;
  }
  if(h == 1){
    if(c == 1 || c == w){
      cout << 1 << endl;
      return 0;
    }
    cout << 2 << endl;
    return 0;
  }
  if(w == 1){
    if(r == 1 || r == h){
      cout << 1 << endl;
      return 0;
    }
    cout << 2 << endl;
    return 0;
  }
}
