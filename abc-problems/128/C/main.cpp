#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
unsigned int e[10] = {0};
unsigned int p[10];
int result = 0;

int main(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int k;
    cin >> k;
    for(int j = 0; j < k; j++){
      unsigned int input;
      cin >> input;
      e[i] = e[i]|(1<<(input-1));
    }
  }
  for(int i = 0; i < m; i++){
    cin >> p[i];
  }

  for(unsigned int s = 0; s < pow(2, n); s++){
    int cnt = 0;
    for(int i = 0; i < m; i++){
      int ans = (bitset<10>(s&e[i]).count()) % 2;
      if(p[i] == ans) cnt++;
    }
    if(cnt == m) result++;
  }
  cout << result << endl;
}
