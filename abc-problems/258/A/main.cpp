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
  int k ;
  cin >> k;
  if(k < 10){
   cout << "21:0" << k << endl;

  } else if (k < 60) {
    cout << "21:" << k << endl;
  } else if (k < 70) {
    cout << "22:0" << k - 60 << endl;
  } else{
    cout << "22:" << k - 60 << endl;
  }
}
