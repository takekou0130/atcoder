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

int n,m,q;
int score[51][4];
ll ans = 0;
vector<int> vec;
void dfs(int v){
  if(vec.size() == n){
    // clac
    ll res = 0;
    rep(j, q){
      if(vec[score[j][1]-1] - vec[score[j][0]-1] == score[j][2]) res += score[j][3];
    }
    chmax(ans, res);
    return;
  }

  rep2(i, v, m+1){
    vec.push_back(i);
    dfs(i);
    vec.pop_back();
  }
}

int main(){
  cin >> n >> m >> q;
  rep(i, q){
    cin >> score[i][0] >> score[i][1] >> score[i][2] >> score[i][3];
  }

  dfs(1);
  cout << ans << endl;
}
