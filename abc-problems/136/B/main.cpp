#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int result = 0;

int main(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    int tmp = i;
    int keta = 0;
    while(tmp > 0 ){
      keta++;
      tmp /= 10;
    }
    if (keta % 2 == 1) result++;
  }
  cout << result << endl;
}
