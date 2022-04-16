#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, k;
vector<int> co;

int main(){
  cin >> a >> b >> k;
  for (int i = 1; i <= 100; i++){
    if(i > a || i > b) break;
    if(a%i == 0 && b%i == 0) co.push_back(i);
  }

  cout << co[co.size()-k]  << endl;
}
