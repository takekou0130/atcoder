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

void f(vector<int> &v, int now, int size, int mx){
  if(v.size() == size){
    rep(i, size){
      cout << v[i];
      if(i != size -1) cout << " ";
    }
    cout << endl;
  }

  rep2(i, now+1, mx+1){
    v.push_back(i);
    f(v, i, size, mx);
    v.pop_back();
  }
}

int main(){
  cin >> n >> m;
  vector<int> v;
  f(v, 0, n, m);
}
