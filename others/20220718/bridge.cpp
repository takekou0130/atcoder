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

struct UnionFind {
  private:
    vector<int> par; // 親
    vector<int> lank; // 木の深さ
    vector<int> volume; // 構成する集合のサイズ
    vector<int> edge; // 構成する集合の辺の数

  public:
    UnionFind(int n){
      // n要素で初期化
      par.resize(n);
      lank.resize(n);
      volume.resize(n);
      edge.resize(n);
      for(int i = 0; i < n; i++){
        par[i] = i;
        lank[i] = 0;
        volume[i] = 1;
        edge[i] = 0;
      }
    }

    // 木の根を求める
    int root(int x){
      if(par[x] == x) return x;
      else return par[x] = root(par[x]);
    }

    // xとyの属する集合を合併
    void unite(int x, int y){
      x = root(x);
      y = root(y);
      if(x == y) {
        edge[x]++;
        return ;
      }
      if(lank[x] < lank[y]) {
        par[x] = y;
        volume[y] += volume[x];
        edge[y] += edge[x] + 1;
      } else {
        par[y] = x;
        volume[x] += volume[y];
        edge[x] += edge[y] + 1;
        if(lank[x] == lank[y]) lank[x]++;
      }
    }

    // xとyが同じ集合に属するか判定
    bool same(int x, int y) { return root(x) == root(y); }
    // xの属する集合の要素数を出力
    int size(int x) { return volume[root(x)]; }
    // xの属する集合の辺の数を出力
    int edge_num(int x) { return edge[root(x)]; }
};


int n,m;
int a[55],b[55];

int main(){
  cin >> n >> m;
  rep(i,m){
    int a_i,b_i;
    cin >> a_i >> b_i;
    a_i--;
    b_i--;
    a[i] = a_i;
    b[i] = b_i;
  }
  int ans = 0;
  rep(i,m){
    UnionFind uf(n);
    rep(j,m){
      if(i == j) continue;
      uf.unite(a[j], b[j]);
    }
    if(!uf.same(a[i], b[i])) ans++;
  }
  cout << ans << endl;
}
