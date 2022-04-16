#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;
int a, b, c, x, y;
ll ans = 10000000000000;
int main(){
  cin >> a >> b >> c >> x >> y;
  // 全部A, Bピザの状態から一枚ずつ置き換えていく
  int z = max(x, y) * 2;
  for(int i = 0; i < z+1; i += 2){
    ll tot = max(a * (x - i/2), 0) + max(b * (y - i/2), 0) + c * i;
    ans = min(ans, tot);
  }
  cout << ans << endl;
}
