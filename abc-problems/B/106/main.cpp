#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int result = 0;

int main(){
  cin >> n;
  for (int i = 1; i <= n; i += 2){
    int yakusuu = 0;
    for (int j = 1; j <= i; j++){
      if (i%j == 0) yakusuu++;
    }
    if (yakusuu == 8) result++;
  }
  cout << result << endl;
}
