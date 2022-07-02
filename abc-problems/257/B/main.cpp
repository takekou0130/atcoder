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

int n,k,q;
bool a[20202];
int main(){
  cin >> n >> k >> q;
  rep(i, 20202) a[i] = false;
  rep(i, k){
    int a_in;
    cin >> a_in;
    a_in--;
    a[a_in] = true;
  }
  rep(i, q){
    int l;
    cin >> l;
    int now = 0;
    int now_idx = 0;
    while(true){
      if(a[now_idx]){
        now++;
      }
      if(now == l){
        if(a[now_idx + 1]){

        } else if (now_idx == n-1) {

        } else {
          a[now_idx] = false;
          a[now_idx+1] = true;
        }
        break;
      }
      now_idx++;
    }
  }

  int cnt = 0;
  int idx = 0;
  while(cnt != k){
    if(a[idx]){
      cout << idx + 1 << " ";
      cnt++;
    }
    idx++;
  }
}
