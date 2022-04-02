#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int main(){
  int x = 5; // 101
  int y = 20; // 10100
  // 立っているbitの数を数えるには__builtin_popcount()を使う
  cout << __builtin_popcount(x) << __builtin_popcount(y) << endl;
}
