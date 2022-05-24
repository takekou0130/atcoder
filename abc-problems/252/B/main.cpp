#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define endl "\n"
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b

int n,k;
int arr[110];

int main(){
  cin >> n >> k;
  rep(i, n) cin >> arr[i];
  int m = 0;
  rep(i, n) chmax(m , arr[i]);
  vector<int> idx;
  rep(i, n) {
    if(arr[i] == m) idx.push_back(i);
  }
  rep(i, k) {
    int b;
    cin >> b;
    b--;
    rep(j, idx.size()){
      if (idx[j] == b) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

}
