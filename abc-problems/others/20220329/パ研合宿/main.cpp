#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n, m;
int arr[101][101];
ll ans;

int main(){
  cin >> n >> m;
  rep(i, n) rep(j, m) cin >> arr[i][j];
  rep(i, m-1){
    rep2(j, i+1, m){
      ll sum = 0;
      rep(k, n){
        sum += max(arr[k][i], arr[k][j]);
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
}
