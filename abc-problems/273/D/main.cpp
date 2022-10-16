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

// c => {-r,-r,-r}
map<ll, vector<ll> > mu;
// c => {r,r,r}
map<ll, vector<ll> > md;
// r => {-c,-c,-c}
map<ll, vector<ll> > ml;
// r => {c,c,c}
map<ll, vector<ll> > mr;
ll h,w,r_s,c_s,n,q;
set<ll> allc;
set<ll> allr;

int main(){
  cin >> h >> w >> r_s >> c_s >> n;
  rep(i, n) {
    ll r,c;
    cin >> r >> c;
    mu[c].push_back(-r);
    md[c].push_back(r);
    ml[r].push_back(-c);
    mr[r].push_back(c);
    allc.insert(c);
    allr.insert(r);
  }

  for(auto c_i: allc){
    sort(mu[c_i].begin(), mu[c_i].end());
    sort(md[c_i].begin(), md[c_i].end());
  }
  for(auto r_i: allr){
    sort(ml[r_i].begin(), ml[r_i].end());
    sort(mr[r_i].begin(), mr[r_i].end());
  }

  cin >> q;
  // r_s,c_sにいる
  rep(i, q){
    ll l;
    char d;
    cin >> d >> l;
    if(d == 'U'){
      if(mu.count(c_s)){
        int kabe_idx = lower_bound(mu[c_s].begin(), mu[c_s].end(), -r_s) - mu[c_s].begin();
        if(kabe_idx == mu[c_s].size()){
          r_s = max(1LL, r_s - l);
          cout << r_s << " " << c_s << endl;
        }else{
          ll kabe = -mu[c_s][kabe_idx];
          r_s = max(r_s - l, kabe+1);
          cout << r_s << " " << c_s << endl;
        }
      } else {
        r_s = max(1LL,r_s - l);
        cout << r_s << " " << c_s << endl;
      }
    }
    if(d == 'D'){
      if(md.count(c_s)){
        int kabe_idx = lower_bound(md[c_s].begin(), md[c_s].end(), r_s) - md[c_s].begin();
        if(kabe_idx == md[c_s].size()){
          r_s = min(h, r_s + l);
          cout << r_s << " " << c_s << endl;
        }else{
          ll kabe = md[c_s][kabe_idx];
          r_s = min(r_s + l, kabe-1);
          cout << r_s << " " << c_s << endl;
        }
      } else {
        r_s = min(h,r_s + l);
        cout << r_s << " " << c_s << endl;
      }
    }
    if(d == 'R'){
      if(mr.count(r_s)){
        int kabe_idx = lower_bound(mr[r_s].begin(), mr[r_s].end(), c_s) - mr[r_s].begin();
        if(kabe_idx == mr[r_s].size()){
          c_s = min(w, c_s + l);
          cout << r_s << " " << c_s << endl;
        }else{
          ll kabe = mr[r_s][kabe_idx];
          c_s = min(c_s + l, kabe-1);
          cout << r_s << " " << c_s << endl;
        }
      } else {
        c_s = min(w,c_s + l);
        cout << r_s << " " << c_s << endl;
      }
    }
    if(d == 'L'){
      if(ml.count(r_s)){
        int kabe_idx = lower_bound(ml[r_s].begin(), ml[r_s].end(), -c_s) - ml[r_s].begin();
        if(kabe_idx == ml[r_s].size()){
          c_s = max(1LL, c_s - l);
          cout << r_s << " " << c_s << endl;
        }else{
          ll kabe = -ml[r_s][kabe_idx];
          c_s = max(c_s - l, kabe+1);
          cout << r_s << " " << c_s << endl;
        }
      } else {
        c_s = max(1LL,c_s - l);
        cout << r_s << " " << c_s << endl;
      }
    }
  }
}
