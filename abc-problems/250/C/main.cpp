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

int n, q;
map<int, int> posToLab;
map<int, int> labToPos;

int main(){
  cin >> n >> q;
  rep2(i,1, n+1){
    posToLab[i] = i;
    labToPos[i] = i;
  }
  rep(i, q){
    int x;
    cin >> x;
    int posi = labToPos[x];
    int swapPos = 0;
    if(posi == n) swapPos = n - 1;
    else swapPos = posi + 1;
    int swapLab = posToLab[swapPos];
    posToLab[posi] = swapLab;
    posToLab[swapPos] = x;
    labToPos[x] = swapPos;
    labToPos[swapLab] = posi;
  }

  rep2(i,1,n+1){
    if(i != n) cout << posToLab[i] << " ";
    else cout << posToLab[i] << endl;
  }
}
