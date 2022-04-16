#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n, k;
ll arr[400001];

int main(){
  cin >> n >> k;
  rep(i, n) cin >> arr[i];
  vector<ll> left(k);
  vector<ll> right(n-k);
  rep(i, k) left[i] = arr[i];
  ll mx = 0;
  rep(i, n-k){
    mx = max(mx, arr[k+i]);
    right[i] = mx;
  }
  bool flag = false;
  int ans = 1e7;
  for(int i = k - 1; i >= 0; i--){
    ll target = left[i];
    int idx = upper_bound(right.begin(), right.end(), target) - right.begin();
    if(idx == n-k) continue;
    flag = true;
    ans = min(ans, (k - 1 - i) + idx + 1);
  }
  if(!flag){
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}
