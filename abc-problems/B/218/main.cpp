#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int main(){
  string dic = "zabcdefghijklmnopqrstuvwxyz";
  rep(i, 26){
    int n;
    cin >> n;
    cout << dic[n];
  }
  cout << endl;
}
