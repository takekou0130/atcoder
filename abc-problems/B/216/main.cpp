#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
string arr[1001][2];

int main(){
  cin >> n;
  rep(i, n){
    cin >> arr[i][0] >> arr[i][1];
  }
  rep(i, n-1){
    rep2(j, i+1, n){
      if(arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1]){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
