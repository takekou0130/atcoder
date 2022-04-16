#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

double x, y;

int main(){
  cin >> x >> y;
  double z = sqrt(x*x + y*y);
  cout << fixed << setprecision(10) << x / z << " " << fixed << setprecision(10) << y / z << endl;
}
