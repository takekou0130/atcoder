#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

string s;

int main(){
  cin >> s;
  int arr[4];
  rep(i, 4) arr[i] = s[i] - '0';
  int cnt = 0;
  rep(i, 3){
    if(arr[i] == arr[i+1]) cnt++;
    if(cnt == 3) { cout << "Weak" << endl; return 0;}
  }
  cnt = 0;
  rep(i, 3){
    if((arr[i] + 1) % 10 == arr[i+1]) cnt++;
    if(cnt == 3) { cout << "Weak" << endl; return 0;}
  }
  cout << "Strong" << endl;
}
