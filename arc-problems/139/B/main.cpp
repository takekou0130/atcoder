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

int t;

int main(){
  cin >> t;
  rep(i, t){
    ll n;
    double a_d, b_d, x_d, y_d, z_d;
    cin >> n >> a_d >> b_d >> x_d >> y_d >> z_d;
    ll a, b, x, y, z;
    a = (ll)a_d;
    b = (ll)b_d;
    x = (ll)x_d;
    y = (ll)y_d;
    z = (ll)z_d;

    double co_x = 1 / x_d;
    double co_y = a_d / y_d;
    double co_z = b_d / z_d;
    // xが一位
    // x > y > z | x > z > y
    if(co_x > co_y && co_x > co_z){
      cout << n * x << endl;
      continue;
    }

    // y > x > z
    if(co_y > co_x && co_x > co_z){
      ll count_y = n / a;
      ll ans = y * count_y;
      ans += x * (n % a);
      cout << ans << endl;
      continue;
    }

    // z > x > y
    if (co_z > co_x && co_x > co_y){
      ll count_z = n / b;
      ll ans = z * count_z;
      ans += x * (n % b);
      cout << ans << endl;
      continue;
    }

    // z > y > x
    if(co_z > co_y && co_y > co_x){
      ll count_z = n / b;
      ll ans = z * count_z;
      ll rest = n - b * count_z;
      ll count_y = rest / a;
      ans += y * count_y;
      rest -= a * count_y;
      ans += x * rest;
      cout << ans << endl;
      continue;
    }

    // y > z > x
    if(co_y > co_z && co_z > co_x){
      ll count_y = n / a;
      ll ans = y * count_y;
      ll rest = n - a * count_y;
      ll count_z = rest / b;
      ans += z * count_z;
      rest -= b * count_z;
      ans += x * rest;
      cout << ans << endl;
      continue;
    }

    // y = z > x
    // コスパが同じ時は小さい方で刻む
    if(a > b){
      ll count_y = n / a;
      ll ans = y * count_y;
      ll rest = n - a * count_y;
      ll count_z = rest / b;
      ans += z * count_z;
      rest -= b * count_z;
      ans += x * rest;
      cout << ans << endl;
      continue;
    } else {
      ll count_z = n / b;
      ll ans = z * count_z;
      ll rest = n - count_z * b;
      ll count_y = rest / a;
      ans += count_y * y;
      rest -= a * count_y;
      ans += x * rest;
      cout << ans << endl;
      continue;
    }
  }
}
