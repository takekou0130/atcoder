#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
vector<ll> a;
vector<ll> b;
vector<ll> c;

int main(){
  cin >> n;
  rep(i, n) { ll in; cin >> in; a.push_back(in); }
  rep(i, n) { ll in; cin >> in; b.push_back(in); }
  rep(i, n) { ll in; cin >> in; c.push_back(in); }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  // b以上のとき、選べるcの総数
  vector<ll> btoc(n);
  for(int i = n-1; i >= 0; i--){
    auto idx_c = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
    if(i == n-1) btoc[i] = n - idx_c;
    else btoc[i] = btoc[i+1] + n - idx_c;
  }

  vector<ll> atob(n);
  for(int i = n-1; i >= 0; i--){
    auto idx_b = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    ll res = 0;
    if(idx_b != n) res = btoc[idx_b];
    if(i == n-1) atob[i] = res;
    else atob[i] = atob[i+1] + res;
  }
  cout << atob[0] << endl;
}
