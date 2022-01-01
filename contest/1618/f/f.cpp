#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T> using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int N = 1e5 + 5;
ll x, y;
string tobinary(ll n){
  string res = "";
  do{
    res = ((n & 1ll ? "1" : "0")) + res;
    n >>= 1ll;
  }while(n);
  return res;
}
void solve() {
  cin >> x >> y;
  string X_bin = tobinary(x), Y_bin = tobinary(y)
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
