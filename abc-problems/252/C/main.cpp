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
string s[110];
int inf = 1e6;

int main(){
  int ans = inf;
  cin >> n;
  rep(i, n) cin >> s[i];
  rep(i, 10){
    char nerai = '0' + i;
    vector<bool> used(n);
    int tot_used = 0;
    int cnt = 0;
    while(tot_used != n){
      rep(j, n){
        if(s[j][cnt % 10] == nerai && !used[j]){
          tot_used++;
          used[j] = true;
          break;
        }
      }
      cnt++;
    }
    chmin(ans, cnt);
  }
  cout << ans-1 << endl;
}
