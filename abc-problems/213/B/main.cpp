#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
ll arr[202020];
ll orig[202020];

int main(){
  cin >> n;
  rep(i, n){
    ll in;
    cin >> in;
    arr[i] = in;
    orig[i] = in;
  }
  sort(arr, arr+n);
  ll v = arr[n-2];
  rep(i, n){
    if(orig[i] == v){
      cout << i+1 << endl;
      return 0;
    }
  }
}
