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
// 広義単調増加の例
vector<int> vec ;
void dfs(int v){
    if(vec.size() == n){
        for(auto el: vec){
          cout << el << " ";
        }
        cout << endl;
        return ;
    }
    for(int i = v ; i <= 5 ; i++){
        vec.push_back(i) ;
        dfs(i) ;
        vec.pop_back() ;
    }
}

int main(){
  cin >> n;
  dfs(1);
}
