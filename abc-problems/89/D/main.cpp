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

int h, w, d,q;
map<int,P> pos;
vector<int> a;
ll cost[90909];

int main(){
  cin >> h >> w >> d;
  rep(i, w){
    rep(j, h){
      int in;
      cin >> in;
      a.push_back(in);
      pos[in] = {i+1, j+1};
    }
  }

  rep(i, 90909) cost[i] = -1;
  sort(a.begin(), a.end());
  for(int i = a.size()-1; i >= 0; i--){
    ll nex = a[i];
    ll cos = 0;
    while(true){
      nex += d;
      if(!pos.count(nex)){
        cost[a[i]] = cos;
        break;
      }
      if(cost[nex] != -1){
        cost[a[i]] = cos + cost[nex];
        break;
      }
      cos += abs(pos[a[i]].first - pos[nex].first) + abs(pos[a[i]].second - pos[nex].second);
    }
  }

  cin >> q;
  rep(i, q){
    int l,r;
    cin >> l >> r;
    cout << cost[r] - cost[l] << endl;
  }
}
