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

vector<int> arr;
int a, b ,c ;

int main(){
  cin >> a >> b >> c;
  arr.push_back(a);
  arr.push_back(b);
  arr.push_back(c);
  sort(arr.begin(), arr.end());
  if(arr[1] == b) cout << "Yes" << endl;
  else cout << "No" << endl;
}
