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

char fi[9][9];
vector<P> parr;
ll ans = 0;

ll diff(P mae, P ato){
  return (mae.first - ato.first) * (mae.first - ato.first) + (mae.second - ato.second) * (mae.second - ato.second);
}

bool check(P pos1, P pos2, P pos3, P pos4){
  if(diff(pos1,pos3) == diff(pos3, pos2) && diff(pos3, pos2) == diff(pos2,pos4) && diff(pos2,pos4) == diff(pos4, pos1) && diff(pos1,pos2) == diff(pos3,pos4)) return true;
  if(diff(pos1,pos2) == diff(pos2, pos4) && diff(pos2, pos4) == diff(pos4,pos3) && diff(pos4,pos3) == diff(pos3, pos1) && diff(pos1,pos4) == diff(pos2,pos3)) return true;
  if(diff(pos1,pos2) == diff(pos2, pos3) && diff(pos2, pos3) == diff(pos3,pos4) && diff(pos3,pos4) == diff(pos4, pos1)  && diff(pos1,pos3) == diff(pos2,pos4)) return true;
  return false;
}

void recursive_comb(int *indexes, int s, int rest) {
  if (rest == 0) {
    if(check(parr[indexes[0]], parr[indexes[1]], parr[indexes[2]], parr[indexes[3]])) ans++;
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
  rep(i, 9){
    string s;
    cin >> s;
    rep(j, 9){
      fi[i][j] = s[j];
      if(s[j] == '#') parr.push_back({i, j});
    }
  }

  if(parr.size() < 4){
    cout << 0 << endl;
    return 0;
  }

  foreach_comb(parr.size(), 4);

  cout << ans << endl;
}
