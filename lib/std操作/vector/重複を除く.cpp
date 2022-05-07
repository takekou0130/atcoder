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

// 参照
// https://qiita.com/ysk24ok/items/30ae72f4f1060b088588

int main(){
  // std::uniqueは隣接する重複要素を削除するが、ゴミが残るのでこれをいい感じに処理する
  std::vector<int> vec = {10,40,40,20,20,30,20,20,40};
  // まずsortして重複要素を隣り合わせにする
  std::sort(vec.begin(), vec.end());
  // unique は返り値として ? の先頭を指すポインタを返す
  // uniqueの時点では 10 20 30 40 ? ? ? ? ?になっている
  // そこで n から最後まで erase すれば完成
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  cout << vec;    // 10 20 30 40
  // setと同じような感じ
}
