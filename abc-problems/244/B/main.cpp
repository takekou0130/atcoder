#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string t;
int x = 0;
int y = 0;

int main(){
  cin >> n >> t;
  string dir = "migi";
  for (int i = 0; i < n; i++){

    if(t[i] == 'S'){
      if(dir == "migi"){
        x++;
      }
      if(dir == "shita"){
        y--;
      }
      if(dir == "hidari"){
        x--;
      }
      if(dir == "ue"){
        y++;
      }
    }
    if(t[i] == 'R'){

      if(dir == "migi"){
        dir = "shita";
        continue;
      }
      if(dir == "shita"){
        dir = "hidari";
        continue;

      }
      if(dir == "hidari"){
        dir = "ue";
        continue;

      }
      if(dir == "ue"){
        dir = "migi";
        continue;

      }
    }
  }
  cout << x << " " << y << endl;
}
