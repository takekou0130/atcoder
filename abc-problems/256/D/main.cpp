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

int n;
int v[202020];

int main(){
  rep(i, 202020) v[i] = 0;
  cin >> n;
  rep(i, n){
    int l,r;
    cin >> l >> r;
    l--;
    r--;
    v[l]++;
    v[r]--;
  }

  bool naka = false;
  int start = 0;
  int now = 0;
  rep(i, 202020){
    if(v[i] == 0) continue;
    if(now == 0 && v[i] > 0){
      start = i;
      now += v[i];
      continue;
    }

    now += v[i];
    if(now == 0){
      cout << start + 1 << " " << i + 1 << endl;
    }
  }
}
