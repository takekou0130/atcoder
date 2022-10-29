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
  if(diff(pos1,pos2) == diff(pos2, pos3) && diff(pos3, pos4) && diff(pos4, pos1)) return true;
  return false;
}

void dfs(vector<P> &calc, int now){
  if(calc.size() == 4) {
    rep(i, 4) {
      cout << "c" << i << "f" << calc[i].first << ":c" << i << "s" << calc[i].second << endl;
    }
    // if(check(calc[0], calc[1], calc[2], calc[3])) ans++;
    calc.pop_back();
    return;
  }

  if(parr.size() <= now) return;
  calc.push_back(parr[now]);
  dfs(calc, now+1);
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

  vector<P> calc;
  dfs(calc, 0);

  cout << ans << endl;
}
