#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n, x;
int a[101];

int main(){
  cin >> n >> x;
  rep(i, n) cin >> a[i];
  rep(i, n){
    if(i%2 == 0) x -= a[i];
    else x = x - a[i] + 1;
    if(x < 0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
