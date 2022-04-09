// 1~Nについて最長の連続する文字列をみる+0のとき

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
// i+1個の連続する1が並んでいるかどうか
bool up[303030];
// i+1個の連続する0が並んでいるかどうか
bool down[303030];
// なにもかえないときで1
ll ans = 1;

int main(){
  cin >> n;
  for(int i = 0; i < 303030; i++){
    up[i] = false;
    down[i] = false;
  }
  int length = 1;
  int past;
  cin >> past;
  if(past == 1) up[0] = true;
  if(past == 0) down[0] = true;


  for(int i = 1; i < n; i++){
    int current;
    cin >> current;
    if(past == current){
      length++;
      if(current == 1) up[length-1] = true;
      if(current == 0) down[length-1] = true;
      continue;
    }
    if(past != current){
      length = 1;
      past = current;
      if(current == 1) up[length-1] = true;
      if(current == 0) down[length-1] = true;
      continue;
    }
  }


  for(int i = 0; i < 303030; i++){
    if(up[i]){
      ans++;
    }
    if(down[i]){
      ans++;
    }
  }

  cout << ans << endl;
}
