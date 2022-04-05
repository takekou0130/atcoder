#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int k;
ll n;

int main(){
  cin >> n;
  while(n > 0){
    n /= 2;
    k++;
  }
  cout << k - 1 << endl;
}
