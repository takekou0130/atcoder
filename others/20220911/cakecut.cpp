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

int n,w,d;
// area, w, d
TP cake[202];

void solv(int n, int w, int d){
  rep(i, 202) cake[i] = {-1, -1, -1};
  cake[0] = {w*d, w, d};

  rep(i,n){
    int p,s;
    cin >> p >> s;
    p--;

    rep2(j,p,i){
      swap(cake[j],cake[j+1]);
    }

    int c_w = get<1>(cake[i]);
    int c_d = get<2>(cake[i]);
    s = (s % (c_w*2+c_d*2));
    TP new_c1,new_c2;
    if(s < c_w){
      new_c1 = {c_d*s , s, c_d};
      new_c2 = {c_d*(c_w-s) , c_w-s, c_d};
    } else if(s < c_d + c_w) {
      new_c1 = {(s-c_w)*c_w , c_w , s-c_w};
      new_c2 = {(c_d - (s-c_w))*c_w , c_w , c_d- (s-c_w)};
    } else if (s < c_d + c_w + c_w) {
      new_c1 = {(s-c_d-c_w)*c_d, s-c_d-c_w, c_d};
      new_c2 = {(c_w-(s-c_d-c_w)) * c_d, c_w-(s-c_d-c_w), c_d};
    } else {
      new_c1 = {c_w*(s-c_d-c_w-c_w), c_w, s-c_d-c_w-c_w};
      new_c2 = {c_w*(c_d-(s-c_d-c_w-c_w)), c_w, c_d-(s-c_d-c_w-c_w)};
    }

    if(get<0>(new_c1) < get<0>(new_c2)){
      cake[i] = new_c1;
      cake[i+1] = new_c2;
    } else {
      cake[i] = new_c2;
      cake[i+1] = new_c1;
    }
  }

  sort(cake, cake+n+1);
  rep(i, n+1){
    cout << get<0>(cake[i]);
    if(i != n) cout << " ";
  }
  cout << endl;
}

int main(){
  while(true){
    cin >> n >> w >> d;
    if(n == 0 && w == 0 && d == 0) break;
    solv(n,w,d);
  }
}
