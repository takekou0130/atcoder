#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll arr[202020][2];
map<ll, int> right_min;
map<ll, int> left_max;
string s;

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    ll x,y;
    cin >> x >> y;
    arr[i][0] = x;
    arr[i][1] = y;
  }
  cin >> s;

  for (int i = 0; i < n; i++){
    if (s[i] == 'R'){
      if (left_max.find(arr[i][1]) != left_max.end() && left_max[arr[i][1]] > arr[i][0]){
        cout << "Yes" << endl;
        return 0;
      }
      if (right_min.find(arr[i][1]) == right_min.end()) {
        right_min[arr[i][1]] = arr[i][0];
      }
      if (right_min.find(arr[i][1]) != right_min.end() && right_min[arr[i][1]] > arr[i][0]) {
        right_min[arr[i][1]] = arr[i][0];
      }
    }

    if (s[i] == 'L'){
      if (right_min.find(arr[i][1]) != right_min.end() && right_min[arr[i][1]] < arr[i][0]){
        cout << "Yes" << endl;
        return 0;
      }
      if (left_max.find(arr[i][1]) == left_max.end()) {
        left_max[arr[i][1]] = arr[i][0];
      }
      if (left_max.find(arr[i][1]) != left_max.end() && left_max[arr[i][1]] < arr[i][0]) {
        left_max[arr[i][1]] = arr[i][0];
      }
    }
  }
  cout << "No" << endl;
}
