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

int n,x,y,z;
int a[1010],b[1010],c[1010];
int main(){
  cin >> n >> x >> y >> z;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) c[i] = a[i]+b[i];
  vector<int> seen(n, 0);

  map<int, vector<int> > mp;
  rep(i, n) mp[a[i]].push_back(i);
  auto itr = mp.end();
  while(itr != mp.begin()){
    itr--;
    auto vec = (*itr).second;
    for(int v: vec){
      if(x == 0){
        break;
      }
      seen[v] = 1;
      x--;
    }
    if(x==0) break;
  }

  map<int, vector<int> > mp2;
  rep(i,n){
    if(!seen[i]) mp2[b[i]].push_back(i);
  }
  auto itr2 = mp2.end();
  while(itr2 != mp2.begin()){
    itr2--;
    auto vec = (*itr2).second;
    for(int v: vec){
      if(y == 0){
        break;
      }
      seen[v] = 1;
      y--;
    }
    if(y == 0) break;
  }

  map<int, vector<int> > mp3;
  rep(i, n){
    if(!seen[i]) mp3[c[i]].push_back(i);
  }
  auto itr3 = mp3.end();
  while(itr3 != mp3.begin()){
    itr3--;
    auto vec = (*itr3).second;
    for(int v: vec){
      if(z == 0){
        break;
      }
      seen[v] = 1;
      z--;
    }
    if(z == 0) break;
  }

  rep(i, n) {
    if(seen[i]) cout << i+1 << endl;
  }
}
