#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
map<ll, ll> mp;
int max_value = 0;
ll max_key;

int main(){
  cin >> n;
  rep(i, n){
    ll k;
    cin >> k;
    mp[k]++;
    if(mp[k] > max_value){
      max_key = k;
      max_value = mp[k];
    }
  }
  cout << max_key << " " << max_value << endl;
}
