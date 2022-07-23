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

ll n,x,y;

// true -> blue , false -> red
ll cnt(ll level, bool color){
  if(color){
    if (level == 2) return y;
    return cnt(level-1, false) + cnt(level-1, true)*y;
  } else {
    if(level == 1) return 0;
    return cnt(level-1, false) + cnt(level, true)*x;
  }
}

int main(){
  cin >> n >> x >> y;
  cout << cnt(n, false) << endl;
}
