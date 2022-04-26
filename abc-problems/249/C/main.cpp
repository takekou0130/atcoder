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

int n, k;
string arr[16];
int ans = 0;

int main(){
  cin >> n >> k;
  rep(i, n){
    cin >> arr[i];
  }

  rep2(i, 1, pow(2, n)){
    int bit = i;
    int cnt = 0;
    map<char, int> m;
    while(bit > 0){
      if(bit & 1>>0){
        rep(j, arr[cnt].size()){
          m[arr[cnt][j]]++;
        }
      }
      bit /= 2;
      cnt++;
    }

    int total = 0;
    for (const auto& [key, value]: m){
      if(value == k) total++;
    }
    chmax(ans, total);
  }
  cout << ans << endl;
}
