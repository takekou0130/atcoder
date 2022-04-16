#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int a, b, c, d;

int main(){
  cin >> a >> b >> c >> d;
  if  (a < c){
    cout << "Takahashi" << endl;
  return 0;
  }
  if  (a == c && b < d){
    cout << "Takahashi" << endl;
  return 0;
  }
  if (a == c && b == d){
    cout << "Takahashi" << endl;
  return 0;
  }

  cout << "Aoki" << endl;
}
