#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    if (i == 0) continue;
    if (i == 1){
      if (s[i - 1] == 'o' && s[i] == 'o') {
        cout << "No" << endl;
        exit(0);
      }
      continue;
    }
    if (s[i] == 'x') {
      if (s[i-2] == 'o' && s[i-1] == 'x') continue;
      if (s[i-2] == 'x' && s[i-1] == 'o') continue;
      cout << "No" << endl;
      return 0;
    } else {
      if (s[i-2] == 'x' && s[i-1] == 'x') continue;
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
