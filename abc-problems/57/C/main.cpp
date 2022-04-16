#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<ll> v;
ll cnt = 0;

ll keta(ll n){
  ll result = 0;
  while(n != 0){
    result++;
    n /= 10;
  }
  return result;
}

int main(){
  cin >> n;
  for (ll i = 1; i*i <= n; i++){
    if(n % i == 0){
      v.push_back(i);
      cnt++;
    }
  }
  ll a = v[cnt - 1];
  ll b = n / a;
  cout << max(keta(a), keta(b)) << endl;
}


