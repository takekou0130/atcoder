#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define endl "\n"

typedef long long ll;

map<ll, vector<ll> > m;
ll n, q;

int main(){
  cin >> n;
  rep(i, n){
    ll in;
    cin >> in;
    m[in].push_back(i);
  }

  cin >> q;
  rep(i, q){
    ll l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;
    if(m[x].size() == 0){
      cout << 0 << endl;
      continue;
    }

    int idx_l = lower_bound(m[x].begin(), m[x].end(), l) - m[x].begin();
    int idx_r = upper_bound(m[x].begin(), m[x].end(), r) - m[x].begin();
    cout << idx_r - idx_l << endl;

  }
}
