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
set<string> v[21];

void f(int len){
  if(len == 2){
    v[len].insert("()");
  }
  for(auto st: v[len-2]){
    v[len].insert('('+st+')');
  }

  for(int j = 2; j <= len-2; j += 2){
    for(auto st: v[j]){
      for(auto st2: v[len-j]){
        v[len].insert(st+st2);
      }
    }
  }
}

int main(){
  cin >> n;
  if(n%2==1) return 0;
  for(int i = 2; i <= n; i += 2){
    f(i);
  }
  for(auto st: v[n]){
    cout << st << endl;
  }
}
