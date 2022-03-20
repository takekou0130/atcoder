#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
bool arr[2002];

int main(){
  cin >> n;
  for(int i = 0; i < 2002; i++){
    arr[i] = false;
  }

  while(true){

    for(int j = 0; j < 2002; j++){
      if(arr[j]) continue;
      arr[j] = true;
      cout << j+1 << endl;
      break;
    }

    int i;
    cin >> i;
    if(i == 0) break;
    arr[i-1] = true;
  }
}
