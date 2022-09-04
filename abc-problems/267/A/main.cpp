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

int main(){
  string s;
  cin >> s;
  if (s == "Monday"){
    cout << 5 << endl;
  }
  if (s == "Tuesday"){
    cout << 4 << endl;
  }
  if (s == "Wednesday"){
    cout << 3 << endl;
  }
  if (s == "Thursday"){
    cout << 2 << endl;
  }
  if (s == "Friday"){
    cout << 1 << endl;
  }
}
