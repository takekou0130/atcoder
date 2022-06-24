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
  // vectorのとき
  vector<int> v;
  v.push_back(2);
  v.push_back(5);
  v.push_back(10);
  v.push_back(11);
  // この時点ではitratorが返るので*でデリファレンスする必要がある
  auto low_itr = lower_bound(v.begin(), v.end(), 5);
  auto upp_itr = upper_bound(v.begin(), v.end(), 5);
  // 5 と 10になる
  cout << *low_itr << " " << *upp_itr << endl;
  // index
  int low_idx = lower_bound(v.begin(), v.end(), 5) - v.begin();
  int out_idx = lower_bound(v.begin(), v.end(), 12) - v.begin();
  int upp_idx = upper_bound(v.begin(), v.end(), 5) - v.begin();
  // 1 2 4となる。見つからないときは配列の大きさ(4)になる
  cout << low_idx << " " << upp_idx << " " << out_idx << endl;


  // 配列のとき
  int n = 4;
  int a[n] = {2, 5, 10, 11};

  // この時点ではitratorが返るので*でデリファレンスする必要がある
  auto low_arr_itr = lower_bound(a, a+n, 5);
  auto upp_arr_itr = upper_bound(a, a+n, 5);
  // 5 と 10になる
  cout << *low_arr_itr << " " << *upp_arr_itr << endl;
  // index
  int low_arr_idx = lower_bound(a, a+n, 5) - a;
  int out_arr_idx = lower_bound(a, a+n, 12) - a;
  int upp_arr_idx = upper_bound(a, a+n, 5) - a;
  // 1 2 4となる。見つからないときは配列の大きさ(4)になる
  cout << low_arr_idx << " " << upp_arr_idx << " " << out_arr_idx << endl;
}
