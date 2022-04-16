#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
vector<vector<ll> > v;

int main(){
  cin >> n;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  vector<ll> fir = {1};
  v.push_back(fir);
  for(int i = 1; i < n; i++){
    vector<ll> past = v[i-1];
    vector<ll> now = past;
    now.push_back(i+1);
    rep(j, past.size()){
      now.push_back(past[j]);
    }
    v.push_back(now);
  }

  vector<ll> result = v[n-1];
  rep(i, result.size()){
    cout << result[i] << " ";
  }
  cout << endl;
}
