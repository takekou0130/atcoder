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

vector<int> combination;
void dfs(int dep, int pre, int size, int min, int max){
  if (dep == size){
    rep(i, size){
      cout << combination[i] << " ";
    }
    cout << endl;
  }
  else {
    for(int i = pre + 1; i < max+1; i++){
      combination[dep] = i;
      dfs(dep+1, i, size, min, max);
    }
  }
}

int main(){
  int size, min, max;
  cin >> size >> min >> max;
  combination.resize(size);
  dfs(0,0, size, min, max);
}
