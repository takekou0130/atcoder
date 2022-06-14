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

int n,q;
string s;

int sum[101010];

int main(){
  cin >> n >> q >> s;
  rep(i, n+10) sum[i] = 0;
  char past = s[0];
  rep2(i, 1, n){
    if(past == 'A' && s[i] == 'C'){
      sum[i+1] = sum[i] + 1;
    } else {
      sum[i+1] = sum[i];
    }
    past = s[i];
  }

  rep(i, q){
    int l,r;
    cin >> l >> r;
    cout << sum[r] - sum[l] << endl;
  }
}
