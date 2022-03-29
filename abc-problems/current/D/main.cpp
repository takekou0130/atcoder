#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n, m;
int a[101];
int b[101];
int c[201];

int main(){
  cin >> n >> m;
  rep(i,n){
    cin >> a[i];
  }
  rep(i, n+m){
    cin >> c[i];
  }
  rep(i, n+m){
    ll sum = 0;
    rep(j, i){
      sum += b[j] * a[i-j];
    }
    b[i] = (c[i] - sum) / a[0];
  }

  rep(i, m){
    cout << b[i] << " ";
    if(i == m -1) cout << endl;
  }
}
