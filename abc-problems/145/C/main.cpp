#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

typedef long long ll;

int n;

int main(){
  cin >> n;
  vector<vector<int> > v(n, vector<int>(2, 0));
  rep(i, n) cin >> v[i][0] >> v[i][1];
  double len = 0;
  double cnt = 0;
  vector<int> arr(n);
  rep(i, n) arr[i] = i;
  do {
    cnt++;
    rep(i, n-1) len += sqrt((v[arr[i]][0] - v[arr[i+1]][0]) * (v[arr[i]][0] - v[arr[i+1]][0]) + (v[arr[i]][1] - v[arr[i+1]][1]) * (v[arr[i]][1] - v[arr[i+1]][1]));
  } while (next_permutation(arr.begin(), arr.end()));
  cout << fixed << setprecision(10) << len / cnt << endl;
}
