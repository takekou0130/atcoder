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
int p[101010];
ll a[101010],b[101010],c[101010];

int main(){
  cin >> n >> m;
  rep(i, m){
    int p_in;
    cin >> p_in;
    p_in--;
    p[i] = p_in;
  }
  rep(i, n-1) cin >> a[i] >> b[i] >> c[i];
  vector<ll> imos(n,0);
  rep(i,m-1){
    imos[min(p[i],p[i+1])]++;
    imos[max(p[i],p[i+1])]--;
  }
  vector<ll> sum(n, 0);
  sum[0] = imos[0];
  rep(i, n-1){
    sum[i+1] = sum[i]+imos[i+1];
  }
  ll ans = 0;
  rep(i, n-1){
    ans += min(a[i]*sum[i], b[i]*sum[i]+c[i]);
  }
  cout << ans << endl;
}
