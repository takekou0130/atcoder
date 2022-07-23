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

int n,x,y,z;
int a[1010],b[1010],c[1010];

int main(){
  cin >> n >> x >> y >> z;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i] ;
  rep(i, n) c[i] = a[i] + b[i];

  vector<int> seen(n, 0);

  vector<P> x_coho;
  rep(i, n) x_coho.push_back({-a[i], i});
  sort(x_coho.begin(),x_coho.end());
  rep(i, x){
    seen[x_coho[i].second] = 1;
  }

  vector<P> y_coho;
  rep(i, n){
    if(!seen[i]) y_coho.push_back({-b[i], i});
  }
  sort(y_coho.begin(), y_coho.end());
  rep(i, y){
    seen[y_coho[i].second] = 1;
  }

  vector<P> z_coho;
  rep(i, n){
    if(!seen[i]) z_coho.push_back({-c[i], i});
  }
  sort(z_coho.begin(), z_coho.end());
  rep(i, z) seen[z_coho[i].second] = 1;

  rep(i, n) {
    if(seen[i]) cout << i+1 << endl;
  }
}
