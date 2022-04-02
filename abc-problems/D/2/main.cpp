#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n,m;
vector<pair<int, int> > v;
int ans;

int main(){
  cin >> n >> m;
  rep(i, m){
    pair<int, int> p;
    cin >> p.first >> p.second;
    v.push_back(p);
  }
  rep(i, pow(2, n)){
    bool flag = true;
    vector<int> h;
    int cnt = 0;
    int now = i;
    while(now > 0){
      cnt++;
      if(now & 1<<0) h.push_back(cnt);
      now /= 2;
    }
    rep(j, (int)h.size()-1){
      rep2(k, j+1, (int)h.size()){
        bool flag2 = false;
        rep(l, m){
          if(h[j] == v[l].first && h[k] == v[l].second) flag2 = true;
          if(h[j] == v[l].second && h[k] == v[l].first) flag2 = true;
        }
        if(flag2) continue;
        flag = false;
      }
    }
    if(flag) ans = max(ans, __builtin_popcount(i));
  }
  cout << ans << endl;
}
