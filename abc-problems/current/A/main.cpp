#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
ll k;
ll arr[101010];

int main(){
  cin >> n >> k;
  rep(i, n){
    cin >> arr[i];
    if(arr[i] == 0) {
      cout << n << endl;
      return 0;
    }
  }

  int ans = 0;
  int left = 0;
  int right = 0;
  ll pro = arr[right];
  while(left < n){
    if(left <= right && pro <= k){
      ans = max(ans, right - left + 1);
      if(right < n-1){
        right++;
        pro *= arr[right];
        continue;
      }
    }

    if(left == right && right < n-1){
      right++;
      pro *= arr[right];
      continue;
    }

    left++;
    pro /= arr[left];
    if(pro <= k) ans = max(ans, right - left +1);
  }
  cout << ans << endl;
}
