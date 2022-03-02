#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
char arr[120];

int main(){
  cin >> n;
  for(int i = 0; i < 120; i++){
    if (n == 0) break;
    if (n%2 != 0){
      n--;
      arr[i] = 'A';
    }else{
      n /= 2;
      arr[i] = 'B';
    }
  }

  string result;
  for(int i = 119; i >= 0; i--){
    if (arr[i] == 0) continue;
    result += arr[i];
  }
  cout << result << endl;
}
