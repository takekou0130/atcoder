#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int result = 0;
int arr[15][15];

int main(){
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      arr[i][j] = 2;
    }
  }
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    for(int j = 0; j < a; j++){
      int x,y;
      cin >> x >> y;
      arr[i][x - 1] = y;
    }
  }

  for(int i = 0; i < pow(2, n); i++){
    bitset<15> bs(i);
    bool flag = true;
    for(int j = 0; j < 15; j++){
      // 不審者なら無視する
      if(bs[j] == 0) continue;

      // 正直者なら処理する
      for(int k = 0; k < 15; k++){
        if(arr[j][k] == 2) continue;
        if(arr[j][k] == bs[k]) continue;
        flag = false;
      }
    }

    if (flag) result = max(result, (int)bs.count());
  }
  cout << result << endl;
}
