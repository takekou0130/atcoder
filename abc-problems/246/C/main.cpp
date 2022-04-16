#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll n, k, x;
ll arr[200001];

int main(){
  cin >> n >> k >> x;
  rep(i, n) cin >> arr[i];
  // 0以下にならないように使えるだけ使う
  rep(i, n){
    if(k <= 0){
      break;
    }
    ll target = arr[i];
    ll can = target / x;
    if (can <= k){
      target -= can * x;
      k -= can;
      arr[i] = target;
    } else {
      target -= k * x;
      k = 0;
      arr[i] = target;
    }
  }
  // rep(i, n){
  //   ll in;
  //   cin >> in;
  //   q.push(in);
  // }
  if(n <= k){
    cout << 0 << endl;
    return 0;
  }
  // ここまででギリギリになっているはずなので大きい方から消していく
  sort(arr, arr+n, greater< ll >());
  ll ans = 0;
  rep2(i, k, n){
    ans += arr[i];
  }
  // while(k > 0){
  //   ll target = q.top();
  //   q.pop();
  //   ll can = target / x;
  //   target -= can * x;
  //   if(target < 0) target = 0;
  //   q.push(target);
  //   k--;
  // }
  // ll ans = 0;
  // while(!q.empty()){
  //   ans += q.top();
  //   q.pop();
  // }
  cout << ans << endl;
}
