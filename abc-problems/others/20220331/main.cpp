#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
vector<ll> A;
vector<ll> B;


int main(){
  cin >> n;
  rep(i, n){
    ll a, b;
    cin >> a >> b;
    A.push_back(a);
    B.push_back(b);
  }


  ll dist_a = 9999999999999999;
  ll dist_b = 9999999999999999;
  rep(i, n){
    ll sum = 0;
    rep(j, n){
      sum += abs(A[i] - A[j]);
    }
    dist_a = min(dist_a, sum);
  }
  rep(i, n){
    ll sum = 0;
    rep(j, n){
      sum += abs(B[i] - B[j]);
    }
    dist_b = min(dist_b, sum);
  }
  ll dist_c = 0;
  rep(i, n) dist_c += B[i] - A[i];
  cout << dist_a + dist_b + dist_c << endl;
}
