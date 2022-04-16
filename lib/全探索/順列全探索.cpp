#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;

int main(){
  cin >> n;
  // 参照する番号の配列。これは昇順にsortされていないといけない
  vector<int> ord(n);
  rep(i, n) ord[i] = i;
  // このループの時点で計算量はO(N!)
  // N = 12で4.79*10^8くらいでここまでは計算可能
  do {
    // これやるとO(N*N!)
    rep(i, n){
    }
  } while(next_permutation(ord.begin(), ord.end()));
}
