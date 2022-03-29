#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;
ll k;
vector<ll> a;
vector<ll> b;

bool v[202020][4];

int main(){
  cin >> n >> k;
  if (n == 1){
    cout << "Yes" << endl;
    return 0;
  }
  rep(i, n){
    ll in;
    cin >> in;
    a.push_back(in);
  }
  rep(i, n){
    ll in;
    cin >> in;
    b.push_back(in);
  }

  for(int i = 0; i < n-1; i++){
    rep(j, 4){
      v[i][j] = false;
    }
    if(abs(a[i] - a[i+1]) <= k) v[i][0] = true;
    if(abs(a[i] - b[i+1]) <= k) v[i][1] = true;
    if(abs(b[i] - a[i+1]) <= k) v[i][2] = true;
    if(abs(b[i] - b[i+1]) <= k) v[i][3] = true;
  }

  // a, b, c（どちらでもOK）の３種類
  char past = 'c';
  rep(i, n-1){
    auto current = v[i];
    if(current[0] && current[1] && current[2] && current[3]){
      past = 'c';
      continue;
    }
    if(current[0] && current[1] && current[2]){
      if(past == 'a' || past == 'c') past = 'c';
      if(past == 'b') past = 'a';
      continue;
    }
    if(current[0] && current[1] && current[3]){
      if(past == 'a' || past == 'c') past = 'c';
      if(past == 'b') past = 'b';
      continue;
    }
    if(current[0] && current[2] && current[3]){
      if(past == 'b' || past == 'c') past = 'c';
      if(past == 'a') past = 'a';
      continue;
    }
    if(current[1] && current[2] && current[3]){
      if(past == 'b' || past == 'c') past = 'c';
      if(past == 'a') past = 'b';
      continue;
    }
    if(current[0] && current[1]){
      if(past == 'b'){
        cout << "No" << endl;
        return 0;
      }
      past = 'c';
      continue;
    }
    if(current[0] && current[2]){
      past = 'a';
      continue;
    }
    if(current[0] && current[3]){
      if(past == 'a') past = 'a';
      if(past == 'b') past = 'b';
      if(past == 'c') past = 'c';
      continue;
    }
    if(current[1] && current[2]){
      if(past == 'a') past = 'b';
      if(past == 'b') past = 'a';
      if(past == 'c') past = 'c';
      continue;
    }
    if(current[1] && current[3]){
      past = 'b';
      continue;
    }
    if(current[2] && current[3]){
      if(past == 'a'){
        cout << "No" << endl;
        return 0;
      }
      past = 'c';
      continue;
    }
    if(current[0]){
      if(past == 'b'){
        cout << "No" << endl;
        return 0;
      }
      past = 'a';
      continue;
    }
    if(current[1]){
      if(past == 'b'){
        cout << "No" << endl;
        return 0;
      }
      past = 'b';
      continue;
    }
    if(current[2]){
      if(past == 'a'){
        cout << "No" << endl;
        return 0;
      }
      past = 'a';
      continue;
    }
    if(current[3]){
      if(past == 'a'){
        cout << "No" << endl;
        return 0;
      }
      past = 'b';
      continue;
    }

    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
}
