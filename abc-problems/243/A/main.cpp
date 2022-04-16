#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int v, a, b, c;

int main(){
  cin >> v >> a >> b >> c;
  int rest = v;
  int count = 0;
  while(true) {
    count++;
    // a
    if (count%3 == 1) {
      rest -= a;
      if (rest < 0){
        cout << 'F' << endl;
        break;
      }
    }
    // b
    if (count%3 == 2) {
      rest -= b;
      if (rest < 0){
        cout << 'M' << endl;
        break;
      }
    }
    // c
    if (count%3 == 0) {
      rest -= c;
      if (rest < 0){
        cout << 'T' << endl;
        break;
      }
    }
  }
}
