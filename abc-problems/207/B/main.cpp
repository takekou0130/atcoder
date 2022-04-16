#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int a, b, c, d;


int main(){
  cin >> a >> b >> c >> d;
  if(b >= c * d){
    cout << -1 << endl;
    return 0;
  }

  int k = a / (c * d -b);
  if((a + k * b ) <= k * c * d){
    cout << k << endl;
    return 0;
  }
  cout << k+1 << endl;
}
