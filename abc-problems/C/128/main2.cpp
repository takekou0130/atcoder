#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n, m;
vector<vector<int> > v;
vector<int> p;
int ans;

int main(){
  cin >> n >> m;
  rep(i, m){
    vector<int> in;
    int k;
    cin >> k;
    rep(j, k){
      int s;
      cin >> s;
      in.push_back(s);
    }
    v.push_back(in);
  }
  rep(i, m){
    int s;
    cin >> s;
    p.push_back(s);
  }

  rep(s, pow(2, n)){
    bool flag = true;
    rep(i, m){
      int cnt = 0;
      auto lights = v[i];
      rep(j, (int)lights.size()){
        if(s & 1<<lights[j]-1) cnt++;
      }
      if(cnt%2 != p[i]) flag = false;
    }
    if(flag) ans++;
  }
  cout << ans << endl;
}
