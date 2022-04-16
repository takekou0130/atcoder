#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
int result = 0;
map<char,vector<int> > mp;

bool contain(char a, char b, char c){
  if (mp[a].empty()) return false;
  if (mp[b].empty()) return false;
  if (mp[c].empty()) return false;
  int a_idx = mp[a][0];
  int c_idx = mp[c][mp[c].size() -1];
  auto it = upper_bound(mp[b].begin(), mp[b].end(), a_idx);
  if (it == mp[b].end()) return false;
  auto b_idx = *it;
  if (a_idx < b_idx && b_idx < c_idx){
    return true;

  }

  return false;
}

int main(){
  cin >> n >> s;
  for(int i = 0; i < n; i++){
    mp[s[i]].push_back(i);
  }
  for(int a = 0; a < 10; a++){
    for(int b = 0; b < 10; b++){
      for (int c = 0; c < 10; c++){
        if (contain(to_string(a)[0], to_string(b)[0], to_string(c)[0])) result++;
      }
    }
  }
  cout << result << endl;
}

