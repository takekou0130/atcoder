#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int dp[101010][8];
ll result;
ll mod = 1000000007;

int main(){
  cin >> s;
  string org = "chokudai";

  for(int i = 0; i < (int)org.size(); i++){
    for(int j = 0; j < (int)s.size(); j++){
      char c = s[j];
      if(i == 0){
        if(j == 0){
          if(c == org[i]) dp[j][i]++;
        }else{
          if(c == org[i]){
            dp[j][i] = dp[j - 1][i] + 1;
            dp[j][i] %= mod;
          } else {
            dp[j][i] = dp[j - 1][i];
            dp[j][i] %= mod;
          }
        }
      } else {
        if(j == 0) continue;
        if(c == org[i]){
          dp[j][i] = dp[j - 1][i] + dp[j - 1][i - 1];
          dp[j][i] %= mod;
          continue;
        }
        dp[j][i] = dp[j - 1][i];
      }
    }
  }

  cout << dp[s.size() - 1][7] << endl;
}
