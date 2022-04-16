#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

// 中部を中心として考える方法
int n;
vector<ll> a;
vector<ll> b;
vector<ll> c;

int main(){
  cin >> n;
  rep(i, n) { ll in; cin >> in; a.push_back(in); }
  rep(i, n) { ll in; cin >> in; b.push_back(in); }
  rep(i, n) { ll in; cin >> in; c.push_back(in); }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  // あるbを選んだとき、aは0 <= a < bの値、cはb < c <= 1e9を選べる
  ll ans = 0;
  rep(i, n){
    auto idx_max_a = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    auto idx_min_c = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
    ans += idx_max_a * (n - idx_min_c);
  }
  cout << ans << endl;
}
