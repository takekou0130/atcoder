#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n, k;
int arr[2][202020];
bool dp[2][202020];

int main(){
  cin >> n >> k;
  rep(i, 2) rep(j, n) cin >> arr[i][j];
  rep(i, 2) rep(j, n) dp[i][j] = false;
  dp[0][0] = true;
  dp[1][0] = true;
  rep2(i, 1, n) rep(j, 2){
    if(abs(arr[j][i] - arr[0][i-1]) <= k && dp[0][i-1]) dp[j][i] = true;
    if(abs(arr[j][i] - arr[1][i-1]) <= k && dp[1][i-1]) dp[j][i] = true;
  }
  if(dp[0][n-1] || dp[1][n-1]){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
