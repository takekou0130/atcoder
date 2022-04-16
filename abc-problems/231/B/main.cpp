#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int n;
  cin >> n;
  map <string, int> list;
  for (int i = 0; i < n; i++){
    string s;
    cin >> s;
    if (list.count(s)) {
      list[s] += 1;
    } else {
      list[s] = 1;
    }
  }

  int max = 0;
  string result;
  for (auto p : list) {
    if (max < p.second) {
      max = p.second;
      result = p.first;
    }
  }
  cout << result << endl;
}
