#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int wordNum(char s){
  vector<char> v = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
  };
  for (int i = 0; i < 26; i++) {
    if (v[i] == s) return i;
  }
  return 0;
}

int main(){
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int arr_res[100001];
  for (int i = 0; i < n; i++){
    int def = wordNum(s.at(i)) - wordNum(t.at(i));
    if (def >= 0) {
      arr_res[i] = def;
    } else {
      arr_res[i] = def + 26;
    }
  }

  int tmp = arr_res[0];
  bool flg = false;
  for (int l = 0; l < n; l++){
    if (arr_res[l] != tmp) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
