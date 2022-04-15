#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n,x,y;
int arr[202020];

int main(){
  cin >> n >> x >> y;
  rep(i, n) cin >> arr[i];
  bool flag_x = false;
  bool flag_y = false;
  int l = -1;
  vector<pair<int, int> > ans;
  rep(i, n){
    if(arr[i] < x && arr[i] > y){
      if(flag_x && flag_y && l != -1){
        pair<int, int> p;
        p.first = l;
        p.second = i;
        ans.push_back(p);
      }
      if(l == -1) l = i;
    }
    if(arr[i] > x || arr[i] < y){
      flag_x = false;
      flag_y = false;
      l = -1;
    }
    if(arr[i] == x){
      flag_x = true;
      if(l == -1) l = i;
      if(flag_x && flag_y && l != -1){
        pair<int, int> p;
        p.first = l;
        p.second = i;
        ans.push_back(p);
      }
    }
    if(arr[i] == y){
      flag_y = true;
      if(l == -1) l = i;
      if(flag_x && flag_y && l != -1){
        pair<int, int> p;
        p.first = l;
        p.second = i;
        ans.push_back(p);
      }
    }
  }
  cout << ans.size() << endl;
}
