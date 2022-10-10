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
vector<int> v[101];

int main(){
  cin >> n >> m;
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int x_i;
      cin >> x_i;
      x_i--;
      v[x_i].push_back(i);
    }
  }



  rep(i, n-1) {
    rep2(j, i+1, n) {
      bool flag = false;
      for(int i_x: v[i]){
        for(int j_x: v[j]){
          if(i_x == j_x) flag = true;
        }
      }
      if(flag) continue;
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
