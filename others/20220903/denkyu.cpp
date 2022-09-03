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

vector<int> v;
int n;
int a[101010];

int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  int len = 0;
  int now = (a[0]+1)%2;
  rep(i, n) {
    if(a[i] == now){
      v.push_back(len);
      len = 1;
      now = a[i];
    }else{
      len++;
      now = a[i];
    }
  }
  v.push_back(len);
  v.push_back(0);
  v.push_back(0);

  int ans = 0;
  rep(i, v.size()) chmax(ans, v[i]+v[i+1]+v[i+2]);
  cout << ans << endl;
}
