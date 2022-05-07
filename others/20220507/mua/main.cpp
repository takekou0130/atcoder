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

double p;

double calc(double v){
  return 1 - ((2 * p * log(2) / 3) / (pow(2, (2/3) * v)));
}

int main(){
  cin >> p;
  double lef = 0;
  double rig = 1e9;
  while(rig - lef > 0.00000001){
    double mid = lef + (rig - lef) / 2;
    cout << calc(mid) << endl;
    if(calc(mid) < 0){
      lef = mid;
    } else {
      rig = mid;
    }
  }
  cout << rig + p / pow(2, (2/3) * rig) << endl;
}
