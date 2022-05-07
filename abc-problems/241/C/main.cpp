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

int hol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int ver[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int n;
char arr[1001][1001];

int main(){
  rep(i, 1001) rep(j, 1001) arr[i][j] = 'u';
  cin >> n;
  rep(i, n){
    string s;
    cin >> s;
    rep(j, n) {
      arr[i][j] = s[j];
    }
  }

  rep(i, n) rep(j, n){
    rep(k, 8) {
      int swap = 0;
      bool flag = true;
      rep(l, 6) {
        if(i+(hol[k]*l) < 0 || i+(hol[k]*l) >= n || j+(ver[k]*l) < 0 || j+(ver[k]*l) >= n){
          flag = false;
          break;
        }
        if(arr[i+(hol[k]*l)][j+(ver[k]*l)] == '.') swap++;
        if(swap > 2){
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
