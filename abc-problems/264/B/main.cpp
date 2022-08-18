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

string b = "black";
string w = "white";
string arr[15][15] = {
  {b,b,b,b,b,b,b,b,b,b,b,b,b,b,b},
  {b,w,w,w,w,w,w,w,w,w,w,w,w,w,b},
  {b,w,b,b,b,b,b,b,b,b,b,b,b,w,b},
  {b,w,b,w,w,w,w,w,w,w,w,w,b,w,b},
  {b,w,b,w,b,b,b,b,b,b,b,w,b,w,b},
  {b,w,b,w,b,w,w,w,w,w,b,w,b,w,b},
  {b,w,b,w,b,w,b,b,b,w,b,w,b,w,b},
  {b,w,b,w,b,w,b,w,b,w,b,w,b,w,b},
  {b,w,b,w,b,w,b,b,b,w,b,w,b,w,b},
  {b,w,b,w,b,w,w,w,w,w,b,w,b,w,b},
  {b,w,b,w,b,b,b,b,b,b,b,w,b,w,b},
  {b,w,b,w,w,w,w,w,w,w,w,w,b,w,b},
  {b,w,b,b,b,b,b,b,b,b,b,b,b,w,b},
  {b,w,w,w,w,w,w,w,w,w,w,w,w,w,b},
  {b,b,b,b,b,b,b,b,b,b,b,b,b,b,b},
};

int main(){
  int r,c;
  cin >> r >> c;
  r--;
  c--;
  cout << arr[r][c] << endl;
}
