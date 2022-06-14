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

int prime[101010];
int a[101010];
int sum[101010];

int main(){
  int MAX = 101010;
  rep(i, MAX) prime[i] = 1;
  prime[0] = 0;
  prime[1] = 0;
  for(int i = 2; i < MAX; i++){
    if(!prime[i]) continue;
    for(int j = i*2; j < MAX; j += i){
      prime[j] = 0;
    }
  }

  rep(i, MAX) a[i] = 0;
  for(int i = 0; i < MAX-1; i++){
    if(i%2 == 0) continue;
    if(prime[i] && prime[(i+1)/2]) a[i] = 1;
  }

  sum[0] = 0;
  rep(i, MAX-5) sum[i+1] = sum[i] + a[i];

  int q;
  cin >> q;
  rep(i, q){
    int l,r;
    cin >> l >> r;
    cout << sum[r+1] - sum[l] << endl;
  }
}
