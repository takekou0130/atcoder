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

string ans = "atcoder";
char arr[7];

int main(){
  string s;
  cin >> s;
  rep(i, 7) arr[i] = s[i];
  ll cnt = 0;
  rep(i, 7) {
    char now = ans[i];
    int idx = 0;
    rep(j, 7) {
      if(arr[j] == now) {
        idx = j;
        break;
      }
    }
    while(arr[i] != now){
      swap(arr[idx-1],arr[idx]);
      cnt++;
      idx--;
    }
  }
  cout << cnt << endl;
}
