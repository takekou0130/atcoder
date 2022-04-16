#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int n, x;
  cin >> n >> x;
  int current = x;
  bool result[101010];
  int a[101010];
  for (int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    a[i] = a_i;
    result[i] = false;
  }
  result[current - 1] = true;
  for (int i = 0; i < n; i++) {
    current = a[current - 1];
    if (result[current - 1]) {
      break;
    } else {
      result[current -1] = true;
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++){
    if (result[i]) {
      sum++;
    }
  }
  cout << sum << endl;
}
