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

int n, r, g, b;

int main(){
  cin >> n >> r >> g >> b;
  rep(i,n){
    char t,c;
    cin >> t >> c;
    int def;
    if(t == 'R') def = 1;
    else def = -1;

      if(c == 'R'){
        r += def;
      }
       if(c == 'G'){
        g += def;
      }
       if(c == 'B'){
        b += def;
      }
       if(c == 'Y'){
        r += def;
        g += def;
      }
       if(c == 'M'){
        r += def;
        b += def;
      }
       if(c == 'C'){
        g += def;
        b += def;
      }
       if(c == 'W'){
        r += def;
        b += def;
        g += def;
      }
    if(r == g && g == b){
      cout << g << endl;
      return 0;
    }
  }
  cout << "no" << endl;
}
