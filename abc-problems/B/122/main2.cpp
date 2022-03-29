#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

string s;
int ans = 0;

int main(){
  cin >> s;
  rep(i, s.size()){
    int cnt = 0;
    rep2(j, i, s.size()){
      if(s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T'){
        cnt++;
        continue;
      }
      break;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
