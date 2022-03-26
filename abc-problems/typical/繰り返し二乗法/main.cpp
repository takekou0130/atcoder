#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll n, m, p;
ll result = 1;

int main(){
  cin >> n >> m >> p;
  while(p > 0){
    if(p & 1) result = (result * n) % m;
    n = (n * n) % m;
    p /= 2;
  }

  cout << result << endl;
}
