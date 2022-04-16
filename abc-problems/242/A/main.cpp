#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

double a, b, c, x;

int main(){
  cin >> a >> b >> c >> x;
  if (x <= a) cout << 1 << endl;
  else if (x > b) cout << 0 << endl;
  else cout << fixed << (c / (b - a)) << endl;;
}
