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

  // 昇順
  for(auto itr = s.begin(); itr != s.end(); itr++){
    // *itrで要素を返す
    cout << *itr << endl;
  }

  // 降順
  // この時点ではsは最後の次の要素を指していることに注意（デクリメントしないと正しい値を指さない）
  auto itr2 = s.end();
  while(itr2 != s.begin()){
    // 最初にデクリメントしておくのが重要
    itr2--;
    cout << *itr2 << endl;
  }
}
