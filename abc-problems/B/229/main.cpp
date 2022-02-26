#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll a, b ;
  cin >> a >> b;
  int a_arr[19];
  int b_arr[19];
  for (int i = 0; i < 19; i++) {
    a_arr[i] = a%10;
    a /= 10;
    b_arr[i] = b%10;
    b /= 10;
  }
  for (int i = 0; i < 19; i++ ) {
    int sum = a_arr[i] + b_arr[i];
    if (sum >= 10) {
      cout << "Hard" << endl;
      exit(0);
    }
  }
  cout << "Easy" << endl;
}
