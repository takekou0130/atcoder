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
string s;
int q;
vector<char> s1;
vector<char> s2;

int main(){
  cin >> n >> s >> q;
  rep(i, n){
    s1.push_back(s[i]);
    s2.push_back(s[i+n]);
  }

  bool turned = false;
  rep(i, q){
    int t,a,b;
    cin >> t >> a >> b;
    a--;
    b--;
    char buff;
    if(t == 1){
      // s2が前にある
      if(turned){
        if(b < n) swap(s2[a],s2[b]);
        else if (a < n && b >= n){
          buff = s2[a];
          s2[a] = s1[b-n];
          s1[b-n] = buff;
        } else swap(s1[a-n], s1[b-n]);
      // s1が前にある
      } else {
        if(b < n) swap(s1[a], s1[b]);
        else if (a < n && b >= n){
          buff = s1[a];
          s1[a] = s2[b-n];
          s2[b-n] = buff;
        } else swap(s2[a-n], s2[b-n]);
      }
    }
    if(t == 2){
      turned = !turned;
    }
  }

  if(turned){
    rep(i, n) {
      cout << s2[i];
    }
    rep(i, n) {
      cout << s1[i];
    }
    cout << endl;
  } else {
    rep(i, n) {
      cout << s1[i];
    }
    rep(i, n) {
      cout << s2[i];
    }
    cout << endl;
  }
}
