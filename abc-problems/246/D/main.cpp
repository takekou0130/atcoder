#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll n;

ll f(ll a, ll b){
  return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main(){
  cin >> n;
  ll x = 8e18;
  ll j = 1000000;
  rep(i, 1000001){
    while(f(i, j) >= n && j >= 0){
      x = min(x, f(i, j));
      j--;
    }
  }
  cout << x << endl;
}
