#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll a;
int k;
ll A;

// aがk進数表記で与えられたとき、10進数表記のAに変換するコード
int main(){
  cin >> k >> a;
  int cnt = 0;
  while(a > 0){
    int keta = a % 10;
    A += keta * pow(k, cnt);
    a /= 10;
    cnt++;
  }
  cout << A << endl;
}
