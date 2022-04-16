#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

ll a, b, k;

int main(){
  cin >> a >> b >> k;
  ll count = 0;
  while(a < b){
    count++;
    a *= k;
  }
  cout << count << endl;
}
