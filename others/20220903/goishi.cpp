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

int v[101010];
int n;
int a[101010];
int now_col;
int now_idx;
int main(){
  cin >> n;
  rep(i, n) cin >> v[i];
  rep(i, 101010) a[i] = 0;
  a[0]++;
  now_col = v[0];
  now_idx = 0;
  rep(i, n-1){
    if(i%2 == 0){
      if(now_col == v[i+1]){
        a[now_idx]++;
      }else if (now_idx == 0) {
        a[now_idx]++;
        now_col = v[i+1];
      } else {
        now_idx--;
        a[now_idx] += a[now_idx+1] + 1;
        a[now_idx+1] = 0;
        now_col = v[i+1];
      }
    } else {
      if(now_col == v[i+1]){
        a[now_idx]++;
      } else {
        now_idx++;
        a[now_idx]++;
        now_col = v[i+1];
      }
    }
  }
  int ans = 0;
  if(now_col == 0) {
    if(now_idx%2 == 0){
      for(int i = 0; i <= now_idx; i += 2){
        ans += a[i];
      }
    } else {
      for(int i = 1; i <= now_idx; i += 2){
        ans += a[i];
      }
    }
  } else {
    if(now_idx%2 == 0){
      for(int i = 1; i <= now_idx; i += 2){
        ans += a[i];
      }
    } else {
      for(int i = 0; i <= now_idx; i += 2){
        ans += a[i];
      }
    }
  }

  cout << ans << endl;
}
