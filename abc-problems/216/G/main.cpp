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

int n,m;
vector<int> v[202020];
map<int, vector<int> > mp;
queue<int> que;

int main(){
  cin >> n >>  m;
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int a;
      cin >> a;
      v[i].push_back(a);
    }
    reverse(v[i].begin(), v[i].end());
  }

  rep(i, m){
    if (v[i].size() == 0) continue;

    auto itr = v[i].end() - 1;
    mp[*itr].push_back(i);
    v[i].pop_back();
    if(mp[*itr].size() == 2) que.push(*itr);
  }

  while(!que.empty()){
    int now = que.front();
    que.pop();

    int ft = mp[now][0];
    if(v[ft].size() != 0) {
      auto itr = v[ft].end() - 1;
      mp[*itr].push_back(ft);
      v[ft].pop_back();
      if(mp[*itr].size() == 2) que.push(*itr);
    }
    int sec = mp[now][1];
    if(v[sec].size() != 0) {
      auto itr = v[sec].end() - 1;
      mp[*itr].push_back(sec);
      v[sec].pop_back();
      if(mp[*itr].size() == 2) que.push(*itr);
    }
  }

  rep(i, m) {
    if(v[i].size() != 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
