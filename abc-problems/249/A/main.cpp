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

int a, b, c, d, e, f, x;

int main(){
  cin >> a >> b >> c >> d >> e >> f >> x;
  int t = 0;
  int ao = 0;

  bool rest_t = false;
  int total_walk = 0;
  int count_t = 0;
  rep(i, x){
    if (rest_t){
      count_t++;
      if (count_t == c) {
        count_t = 0;
        rest_t = false;
      }
    } else {
      total_walk++;
      count_t++;
      if(count_t == a){
        count_t = 0;
        rest_t = true;
      }
    }
  }
  t = total_walk * b;

  rest_t = false;
  total_walk = 0;
  count_t = 0;
  rep(i, x){
    if (rest_t){
      count_t++;
      if (count_t == f) {
        count_t = 0;
        rest_t = false;
      }
    } else {
      total_walk++;
      count_t++;
      if(count_t == d){
        count_t = 0;
        rest_t = true;
      }
    }
  }
  ao = total_walk * e;

  if (t > ao){
    cout << "Takahashi" << endl;
    return 0;
  }
  if (t < ao ){
    cout << "Aoki" << endl;
    return 0;
  }
  cout << "Draw" << endl;


}
