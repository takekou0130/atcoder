#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int result = 0;

vector<int> enumdiv(int n){
  vector<int> v;
  for (int i = 1; i*i <= n; i++){
    if(n%i == 0){
      if(i*i == n){
        v.push_back(i);
      } else {
        v.push_back(i);
        v.push_back(n/i);
      }
    }
  }
  return v;
}

int main(){
  cin >> n;
  for (int i = 1; i <= n; i += 2){
    auto v = enumdiv(i);
    if (v.size() == 8) result++;
  }
  cout << result << endl;
}


