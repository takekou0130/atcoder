#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
int result = 0;

int main(){
  cin >> n >> s;
  for(int i = 0; i < n-2; i++){
    char a = s[i];
    if (a == 'A'){
      char b = s[i+1];
      if (b == 'B'){
        char c = s[i+2];
        if (c == 'C') result++;
      }
    }
  }
  cout << result << endl;
}

