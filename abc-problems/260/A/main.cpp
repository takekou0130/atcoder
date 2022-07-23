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
  string s;
  cin >> s;
  char a = s[0];
  char b = s[1];
  char c = s[2];
  if(a == b && b == c){
    cout << -1 << endl;
    return 0;
  }
  if(a == b){
    cout << c << endl;
    return 0;
  }
  if(b == c){
    cout << a << endl;
    return 0;
  }
  if(c == a){
    cout << b << endl;
    return 0;
  }
  cout << a << endl;
}
