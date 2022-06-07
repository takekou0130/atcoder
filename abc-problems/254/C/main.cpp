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

priority_queue<int, vector<int>, greater<int> > v[202020];
int n, k;

int main(){
  cin >> n >> k;
  rep(i, n){
    int in;
    cin >> in;
    v[i%k].push(in);
  }
  int past = 0;
  rep(i, n){
    if(v[i%k].top() >= past){
      past = v[i%k].top();
      v[i%k].pop();
      continue;
    }
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
}
