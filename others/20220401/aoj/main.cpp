#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n, q, ans;
vector<int> S;
vector<int> T;

int main(){
  cin >> n;
  rep(i, n){
    int s;
    cin >> s;
    S.push_back(s);
  }
  cin >> q;
  rep(i, q){
    int t;
    cin >> t;
    T.push_back(t);
  }
  rep(i, q){
    int t = T[i];
    int left = -1;
    int right = (int)S.size();
    while(right - left > 1){
      int mid = left + (right - left) / 2;
      if(S[mid] >= t) right = mid;
      else left = mid;
    }
    if(S[right] == t) ans++;
  }
  cout << ans << endl;
}
