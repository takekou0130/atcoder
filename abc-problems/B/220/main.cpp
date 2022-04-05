#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll a, b;
int k;
ll A, B;

int main(){
  cin >> k >> a >> b;
  int cnt = 0;
  while(a > 0){
    int keta = a % 10;
    A += keta * pow(k, cnt);
    a /= 10;
    cnt++;
  }
  cnt = 0;
  while(b > 0){
    int keta = b % 10;
    B += keta * pow(k, cnt);
    b /= 10;
    cnt++;
  }
  cout << A * B << endl;
}
