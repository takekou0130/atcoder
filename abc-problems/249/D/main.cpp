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
int arr[201010];
ll total = 0;

int main(){
  map<int, ll> m;
  cin >> n;
  rep(i, n){
    cin >> arr[i];
    m[arr[i]]++;
  }
  rep(i, n){
    for(int j = 1; j * j <= arr[i]; j++){
      if(arr[i] % j != 0) continue;

      if (j*j == arr[i]){
        total += m[j] * m[j];
        continue;
      }

      total += m[arr[i] / j] * m[j] * 2;
    }
  }
  cout << total << endl;
}
