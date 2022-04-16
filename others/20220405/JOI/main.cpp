#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll d;
int n, m;
ll D[300003];
ll K[10001];

int main(){
  cin >> d >> n >> m;
  D[0] = 0;
  D[n] = d;
  D[2*n] = d * 2;
  rep2(i, 1, n){
    ll in;
    cin >> in;
    D[i] = in;
    D[i+n] = in + d;
    D[i+2*n] = in + d * 2;
  }
  rep(i, m){
    ll in;
    cin >> in;
    K[i] = in + d;
  }
  sort(D, D+3*n);
  ll ans = 0;
  rep(i, m){
    auto target = K[i];
    auto idx = lower_bound(D, D + 3*n, target) - D;
    ans += min(abs(D[idx] - target),abs(target - D[idx-1]));
  }
  cout << ans << endl;
}
