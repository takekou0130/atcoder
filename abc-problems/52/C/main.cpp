#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define endl "\n"
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b

ll n;
ll mod = 1000000007;

ll insu[1010];
vector<ll> prime;

vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main(){
  cin >> n;
  vector<bool> isprime = Eratosthenes(1000);
  rep(i, 1001) {
    if(isprime[i]) prime.push_back(i);
  }
  rep(i, 1010) insu[i] = 1;
  for(ll i = 1; i <= n; i++) {
    ll crr = i;
    while(crr > 1) {
      for(ll p: prime) {
        if(crr % p == 0) {
          insu[p]++;
          crr /= p;
          break;
        }
      }
    }
  }

  ll ans = 1;
  rep(i, 1010) {
    ans *= insu[i];
    ans %= mod;
  }

  cout << ans << endl;
}
