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

ld dfs(int rest){
  if (rest == 1) return (ld)3.5;
  ld ans = (ld)0;
  ans += max((ld)1,dfs(rest-1)) / 6;
  ans += max((ld)2,dfs(rest-1)) / 6;
  ans += max((ld)3,dfs(rest-1)) / 6;
  ans += max((ld)4,dfs(rest-1)) / 6;
  ans += max((ld)5,dfs(rest-1)) / 6;
  ans += max((ld)6,dfs(rest-1)) / 6;
  return ans;
}

int main(){
  cin >> n;
  cout << fixed << setprecision(10) << dfs(n) << endl;
}
