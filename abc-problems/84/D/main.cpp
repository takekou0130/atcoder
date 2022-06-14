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

vector<int> prime;

bool is_prime(int num){
  for(int j = 2; j*j <= num; j++){
    if(num%j == 0) return false;
  }
  return true;
}

int main(){
  for(int i = 3; i <= 100000; i += 2){
    if(is_prime(i) && is_prime((i+1)/2)) prime.push_back(i);
  }

  int q;
  cin >> q;
  rep(i, q){
    int l,r;
    cin >> l >> r;
    auto lidx = lower_bound(prime.begin(), prime.end(), l) - prime.begin();
    auto ridx = upper_bound(prime.begin(), prime.end(), r) - prime.begin();
    cout << ridx - lidx << endl;
  }
}
