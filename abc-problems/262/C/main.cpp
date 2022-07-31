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
int a[505050];

int main(){
  cin >> n;
  rep(i,n) cin >> a[i];
  // すでに一致してるやつ
  ll res = 0;
  rep(i, n) {
    if(a[i] == i+1) res++;
  }
  ll ans = res * (res - 1LL) / 2LL;

  // 一致してないやつ
  rep(i, n) {
    if(a[i] == i+1) continue;
    if(a[i] > i+1) continue;
    if(a[a[i]-1] == i+1) ans++;
  }

  cout << ans << endl;
}
