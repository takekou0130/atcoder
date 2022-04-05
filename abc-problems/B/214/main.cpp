#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int s,t;

int main(){
  cin >> s >> t;
  int cnt = 0;
  rep(i, 101){
    rep(j, 101){
      rep(k, 101){
        if(i + j + k <= s && i * j * k <= t) cnt++;
      }
    }
  }
  cout << cnt << endl;
}
