#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n ,q;
int A[21];
int m[201];

int main(){
  cin >> n;
  rep(i, n) cin >> A[i];
  cin >> q;
  rep(i, q) cin >> m[i];
  rep(i, q){
    bool flag = false;
    rep2(j, 1 ,pow(2, n)){
      int bit = j;
      int sum = 0;
      int cnt = 0;
      while(bit > 0){
        if(sum > m[i]) break;
        if(bit & 1) sum += A[cnt];
        bit /= 2;
        cnt++;
      }
      if(sum == m[i]){ flag = true; break;}
    }
    if(flag) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
