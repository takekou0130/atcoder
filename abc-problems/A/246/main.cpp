#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int arr[3][2];

int main(){
  rep(i, 3){
    cin >> arr[i][0] >> arr[i][1];
  }
  int x_1 = arr[0][0];
  int x_2;
  if(x_1 == arr[1][0]) x_2 = arr[2][0];
  else x_2 = arr[1][0];
  int cnt_1 = 1;
  int cnt_2 = 0;
  if(arr[1][0] == x_1) cnt_1++;
  else cnt_2++;
  if(arr[2][0] == x_1) cnt_1++;
  else cnt_2++;
  int x_ans;
  if(cnt_1 == 1) x_ans = x_1;
  else x_ans = x_2;

  int y_1 = arr[0][1];
  int y_2;
  int y_ans;
  if(y_1 == arr[1][1]) y_2 = arr[2][1];
  else y_2 = arr[1][1];
  cnt_1 = 1;
  cnt_2 = 0;
  if(arr[1][1] == y_1) cnt_1++;
  else cnt_2++;
  if(arr[2][1] == y_1) cnt_1++;
  else cnt_2++;
  if(cnt_1 == 1) y_ans = y_1;
  else y_ans = y_2;
  cout << x_ans << " " << y_ans << endl;
}
