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

vector<int> all;
vector<int> odd;
int dpall[1000001];
int dpodd[1000001];

int f(int n){
  return n * (n+1) * (n+2) / 6;
}

int main(){
  int n = 0;
  while(true){
    n++;
    int ans = f(n);
    if(ans > 1e6) break;
    all.push_back(ans);
    if(ans % 2 == 1) odd.push_back(ans);
  }


  rep(i, 1000001) dpall[i] = 6;
  rep(i, 1000001) dpodd[i] = 50;
  dpall[0] = 0;
  dpodd[0] = 0;

  rep(j, 1000001){
    rep(i, 179) {
      if(j+all[i] > 1e6) continue;
      if(all[i] == j) dpall[j] = 1;
      chmin(dpall[j+all[i]], dpall[j]+1);
    }
  }

  rep(j, 1000001){
    rep(i, 44) {
      if(j+odd[i] > 1e6) continue;
      if(odd[i] == j) dpodd[j] = 1;
      chmin(dpodd[j+odd[i]], dpodd[j]+1);
    }
  }

  while(true){
    int in;
    cin >> in;
    if(in == 0) break;
    cout << dpall[in] << " " << dpodd[in] << endl;
  }
}
