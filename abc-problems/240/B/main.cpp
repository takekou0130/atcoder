#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
int ans = 0;
set<int> s;

int main(){
  cin >> n;
  rep(i, n){
  ll in;
  cin >> in;
  s.insert(in);
  }

  cout << s.size() << endl;
}
