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

int h_a, h_b, w_a, w_b;
ll a[10][10],b[10][10];
vector<vector<int> > h_cons;
vector<vector<int> > w_cons;

void h_dfs(vector<int> arr, int dep, int prev, int max, int max_num){
  if (dep == max_num+1) {
    vector<int> vec;
    rep(i, dep) vec.push_back(arr[i]);
    h_cons.push_back(vec);
  } else {
    for(int i = prev+1; i <= max; i++){
      arr.push_back(i);
      h_dfs(arr, dep+1, i, max, max_num);
      arr.pop_back();
    }
  }
}

void w_dfs(vector<int> arr, int dep, int prev, int max, int max_num){
  if (dep == max_num+1) {
    vector<int> vec;
    rep(i, dep) vec.push_back(arr[i]);
    w_cons.push_back(vec);
  } else {
    for(int i = prev+1; i <= max; i++){
      arr.push_back(i);
      w_dfs(arr, dep+1, i, max, max_num);
      arr.pop_back();
    }
  }
}

int main(){
  cin >> h_a >> w_a;
  rep(i, h_a) rep(j, w_a){
    cin >> a[i][j];
  }

  cin >> h_b >> w_b;
  rep(i, h_b) rep(j, w_b){
    cin >> b[i][j];
  }

  vector<int> h_con;
  h_dfs(h_con, 0, -1, h_a-1, h_b-1);
  vector<int> w_con;
  w_dfs(w_con, 0, -1, w_a-1, w_b-1);

  for(auto h_cond: h_cons){
    for(auto w_cond: w_cons){
      bool flag = true;
      for(int h = 0; h < h_b; h++) for(int w = 0; w < w_b; w++){
        if(a[h_cond[h]][w_cond[w]] != b[h][w]) {

          flag = false;
          break;
        }
      }
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
