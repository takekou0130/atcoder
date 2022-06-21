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
bool koma[4];
int main(){
  cin >> n;
  int p = 0;
  rep(i,4) koma[i] = false;
  rep(i, n){
    int a;
    cin >> a;
    koma[0] = true;
    for(int j = 3; j >= 0; j--){
      if(!koma[j]) continue;
      if(j+a > 3){
        p++;
        koma[j] = false;
        continue;
      }
      koma[j+a] = true;
      koma[j] = false;
    }
  }

  cout << p << endl;
}
