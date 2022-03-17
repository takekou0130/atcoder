#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c, x, y;
int result = 0;

int main(){
  cin >> a >> b >> c >> x >> y;
  // 全部一枚ずつ買う
  int tmp = a * x + b * y;
  result = tmp;
  // cをi枚買って置き換えていく
  for(int i = 0; i <= max(x, y) *2; i += 2){
    tmp = a * (max(0, x - i / 2)) + b * (max(0, y - i /2)) + c * i;
    if (result > tmp){
      result = tmp;
    }
  }
  cout << result << endl;
}
