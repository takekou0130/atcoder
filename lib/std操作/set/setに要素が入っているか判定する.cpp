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
  set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);

  // setの要素は重複しないので1なら入っていて0なら入っていない
  // 計算量はlog N
  if(s.count(1)) cout << "1は入っている" << endl;
  if(!s.count(3)) cout << "出力されない" << endl;
  if(!s.count(4)) cout << "4は入っていない" << endl;
}
