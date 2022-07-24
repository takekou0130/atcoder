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

ld a,b,w;
int main(){
  cin >> a >> b >> w;
  w *= 1000LL;
  if (a > w){
    cout << "UNSATISFIABLE" << endl;
    return 0;
  }

  ll sho_a = w / a;
  ld rest = w - a * sho_a;
  ld wake = rest / (ld)sho_a;
  ld ans_max = 0;
  if(a + wake <= b) {
    ans_max = sho_a;
  } else {
    cout << "UNSATISFIABLE" << endl;
    return 0;
  }

  ll sho_b = w / b ;
  ld over = w - b * (sho_b + 1);
  ld wake_b = over / (ld)sho_b;
  ld ans_min = 0;
  if (b - over > a){
    ans_min = sho_b+1;
  } else if (b - over == a) {
    ans_min = sho_b;
  } else  {
    cout << "UNSATISFIABLE" << endl;
    return 0;
  }

  cout << ans_min << " " << ans_max << endl;
  }
