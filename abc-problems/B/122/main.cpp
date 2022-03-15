#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int result = 0;
char arr[4] = {'A', 'T', 'G', 'C'};

bool contain(char c){
  for(int i = 0; i < 4; i++){
    if (c == arr[i]) return true;
  }
  return false;
}

int main(){
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++){
    int tmp = 0;
    for (int j = i; j < (int)s.size(); j++){
      if(contain(s[j])) tmp++;
      else break;
    }
    if (tmp > result) result = tmp;
  }
  cout << result << endl;
}


