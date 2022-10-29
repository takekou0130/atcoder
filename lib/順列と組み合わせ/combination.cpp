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

void f(int a){
  // なんか処理する
}

void recursive_comb(int *indexes, int s, int rest) {
  if (rest == 0) {
    // 処理する
    // indexesのsizeはkなのでindexes[k-1]までアクセス可能
    f(indexes[0]);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k);
}

int main(){
  int n,k;
  cin >> n >> k;

  // nCk
  foreach_comb(n, k);
}
