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

int main(){
  cin >> n;
  int sum = 0;
  rep2(i,1,10) rep2(j,1,10 ) sum += i * j;
  int sa = sum - n;
  rep2(i, 1, 10) rep2(j, 1, 10){
    if(sa == i * j) cout << i << " x " << j << endl;
  }
}
