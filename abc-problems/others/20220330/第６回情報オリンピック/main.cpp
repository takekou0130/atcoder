#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
int ans = 0;

vector<int> get_pos(string s){
  int x = stoi(s.substr(1, 4));
  int y = stoi(s.substr(5));
  vector<int> pos(2);
  pos[0] = x;
  pos[1] = y;
  return pos;
}

int area(vector<int> pos1, vector<int> pos2){
  int diff_x = pos1[0] - pos2[0];
  int diff_y = pos1[1] - pos2[1];
  return diff_x * diff_x + diff_y * diff_y;
}

int main(){
  cin >> n;
  vector<string> p(n);
  rep(i, n){
    int x,y;
    cin >> x >> y;
    p[i] = to_string(100000000 + x * 10000 + y);
  }
  sort(p.begin(), p.end());

  rep(i, n-1){
    rep2(j, i+1, n){
      auto pos1 = get_pos(p[i]);
      auto pos2 = get_pos(p[j]);
      vector<int> pos3 = { pos2[0] - pos2[1] + pos1[1], pos2[1] + pos2[0] - pos1[0] };
      vector<int> pos4 = { pos1[0] - pos2[1] + pos1[1], pos1[1] + pos2[0] - pos1[0] };

      rep(i, 2) if (pos3[i] < 0) continue;
      rep(i, 2) if (pos4[i] < 0) continue;
      auto itr3 = lower_bound(p.begin(), p.end(), to_string(100000000 + pos3[0] * 10000 + pos3[1]));
      if(itr3 == p.end() || pos3 != get_pos(*itr3)) continue;
      auto itr4 = lower_bound(p.begin(), p.end(), to_string(100000000 + pos4[0] * 10000 + pos4[1]));
      if(itr4 == p.end() || pos4 != get_pos(*itr4)) continue;
      ans = max(ans, area(pos1, pos2));
    }
  }

  cout << ans << endl;
}
