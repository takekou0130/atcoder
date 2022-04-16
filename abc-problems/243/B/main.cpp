#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>A;
vector<ll>B;
int n;

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    A.push_back(a);
  }
  for (int i = 0; i < n; i++){
    int b;
    cin >> b;
    B.push_back(b);
  }
  int result_1 = 0;
  int result_2 = 0;
  for (int current_a = 0; current_a < n; current_a++){
    ll a = A[current_a];
    for (int c_b = 0; c_b < n; c_b++){
      ll b = B[c_b];
      if (a == b && current_a == c_b){
        result_1++;
        break;
      }
      if (a == b){
        result_2++;
        break;
      }
    }
  }
  cout << result_1 << endl;
  cout << result_2 << endl;
}
