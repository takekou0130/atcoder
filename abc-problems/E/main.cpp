#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
ll k;
int A[1010101];
int F[1010101];

int main(){
  cin >> n >> k;
  rep(i, n){
    cin >> A[i];
  }
  rep(i, n){
    cin >> F[i];
  }
  sort(A, A+n, greater<int>());
  sort(F, F+n);
  ll ng = -1;
  ll ok = 1e12;
  while(ok - ng > 1){
    ll mid = ng + (ok - ng) / 2;
    ll rest = k;
    rep(i, n){
      ll need = max((A[i] - mid / F[i]), (ll)0);
      rest -= need;
    }
    if(rest >= 0) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
