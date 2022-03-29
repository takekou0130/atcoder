#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
vector<int> v;

int main(){
  cin >> n;
  rep(i, n){
    int in;
    cin >> in;
    v.push_back(in);
  }

  rep(i, 2001){
    bool contain = false;
    rep(j, n){
      if(v[j] == i) contain = true;
    }

    if(!contain){
      cout << i << endl;
      return 0;
    }
  }


}
