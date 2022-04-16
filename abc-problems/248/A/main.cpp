#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

string s;
bool arr[10];

int main(){
  cin >> s;
  rep(i, 10) arr[i] = false;
  rep(i, 9){
    int now = s[i] - '0';
    arr[now] = true;
  }
  rep(i, 10){
    if(!arr[i]){
      cout << i << endl;
    }
  }
}
