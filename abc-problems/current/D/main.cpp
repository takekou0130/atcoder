#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int q;
// 値と個数のpair
vector<pair<ll, ll> > v;

int main(){
  cin >> q;
  ll cur_v_idx = 0;
  rep(i, q){
    int type;
    cin >> type;
    if(type == 1){
      ll x,c;
      cin >> x >> c;
      pair<ll, ll> p;
      p.first = x;
      p.second = c;
      v.push_back(p);
    }
    if(type == 2){
      ll c;
      cin >> c;
      ll sum = 0;
      while(c > 0){
        if(v[cur_v_idx].second > c){
          sum += v[cur_v_idx].first * c;
          v[cur_v_idx].second -= c;
          break;
        } else {
          sum += v[cur_v_idx].first * v[cur_v_idx].second;
          c -= v[cur_v_idx].second;
          cur_v_idx++;
        }
      }
      cout << sum << endl;
    }
  }
}
