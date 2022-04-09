#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll L, R;

ll check(ll a, ll b){
  if(a%b == 0) return b;
  return check(b, a%b);
}

int main(){
  cin >> L >> R;
  ll y = R;
  ll x = L;
  for(int i = 0; i < 10000; i++){
    if(check(y, x) == 1) {
      cout << y - x << endl;
      return 0;
    }
    if(i%2 == 0) x++;
    else {
      y--;
      x--;
    }
  }
}
