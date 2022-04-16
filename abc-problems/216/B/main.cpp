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

int n;
string arr[1010][2];

int main(){
  cin >> n;
  rep(i, n) cin >> arr[i][0] >> arr[i][1];
  rep(i, n) rep(j, n) {
    if(arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1] && i != j){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
