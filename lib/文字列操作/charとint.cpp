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
  char a = 'a';
  // charのa
  cout << a << endl;
  // intの97
  cout << (int)a << endl;

  char one = '1';
  // 50になってしまう!!
  cout << one + 1 << endl;

  // これでchar -> int に型変換できる
  int intOne = one - '0';
  cout << "value:" << intOne + 1 << " type:" << typeid(intOne).name() << endl;

  int b = 1;
  char B = b - '0';
  // バグる!!
  cout << "value:" << B << " type:" << typeid(B).name() << endl;
  // これでint -> char に型変換できる
  char charB = b + '0';
  cout << "value:" << charB << " type:" << typeid(charB).name() << endl;
}
