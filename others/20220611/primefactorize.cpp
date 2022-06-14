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

ll n;

int main(){
  cin >> n;
  cout << n << ":";
  while(true){
    bool flag = false;
    for(ll i = 2; i*i <= n; i++){
      if(n%i == 0){
        cout << " " << i;
        n /= i;
        flag = true;
        break;
      }
    }
    if(flag) continue;
    break;
  }
  cout << " " << n << endl;
}
