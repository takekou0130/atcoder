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

int n, m;
int arr[50][2];

int main(){
  cin >> n >> m;
  rep(i, m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    arr[i][0] = a;
    arr[i][1] = b;
  }

  int ans = 0;
  rep(i, m){
    vector<int> G[50];
    vector<bool> seen(50);
    rep(j, m){
      if(i == j) continue;
      G[arr[j][0]].push_back(arr[j][1]);
      G[arr[j][1]].push_back(arr[j][0]);
    }

    queue<int> que;
    que.push(0);
    seen[0] = true;
    while(!que.empty()){
      int idx = que.front();
      que.pop();

      for(auto g: G[idx]){
        if(seen[g]) continue;
        seen[g] = true;
        que.push(g);
      }
    }

    rep(j, n){
      if(!seen[j]){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}
